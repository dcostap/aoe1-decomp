#define NOMINMAX
#include <windows.h>
#include <dia2.h>
#include <diacreate.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct LineChange {
    DWORD rva;
    DWORD line_number;
    std::wstring source_path;
    std::wstring source_file;
};

struct FunctionSummary {
    DWORD va;
    std::wstring symbol_name;
    std::wstring direct_source_path;
    std::wstring primary_source_path;
    std::wstring primary_source_file;
    DWORD line_start;
    DWORD line_end;
    size_t line_record_count;
    size_t line_change_count;
    size_t unique_file_count;
    bool has_line_info;
    bool has_direct_source;
};

static std::wstring bstr_to_wstring(BSTR value) {
    if (value == nullptr) {
        return L"";
    }
    return std::wstring(value, SysStringLen(value));
}

template <typename T>
static void safe_release(T *&ptr) {
    if (ptr != nullptr) {
        ptr->Release();
        ptr = nullptr;
    }
}

static std::string utf8_from_wstring(const std::wstring &value) {
    if (value.empty()) {
        return std::string();
    }
    int size = WideCharToMultiByte(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    std::string utf8(size, '\0');
    WideCharToMultiByte(CP_UTF8, 0, value.c_str(), static_cast<int>(value.size()), utf8.data(), size, nullptr, nullptr);
    return utf8;
}

static std::string csv_escape(const std::string &value) {
    std::string escaped;
    escaped.reserve(value.size() + 8);
    escaped.push_back('"');
    for (char ch : value) {
        if (ch == '"') {
            escaped.push_back('"');
        }
        escaped.push_back(ch);
    }
    escaped.push_back('"');
    return escaped;
}

static std::wstring basename_from_path(const std::wstring &path) {
    size_t slash = path.find_last_of(L"\\/");
    if (slash == std::wstring::npos) {
        return path;
    }
    return path.substr(slash + 1);
}

static std::string hex8(DWORD value) {
    std::ostringstream stream;
    stream << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << value;
    return stream.str();
}

static std::vector<DWORD> load_rvas(const wchar_t *path) {
    std::vector<DWORD> rvas;
    std::ifstream handle{std::filesystem::path(path)};
    if (!handle) {
        return rvas;
    }

    std::string line;
    while (std::getline(handle, line)) {
        if (line.empty()) {
            continue;
        }
        char *end = nullptr;
        unsigned long value = strtoul(line.c_str(), &end, 16);
        if (end == line.c_str()) {
            continue;
        }
        rvas.push_back(static_cast<DWORD>(value));
    }
    return rvas;
}

static bool collect_function_source(
    IDiaSession *session,
    DWORD image_base,
    DWORD requested_va,
    FunctionSummary &summary,
    std::vector<LineChange> &changes
) {
    summary = {};
    summary.va = requested_va;
    DWORD requested_rva = requested_va >= image_base ? (requested_va - image_base) : requested_va;

    IDiaSymbol *symbol = nullptr;
    HRESULT hr = session->findSymbolByRVA(requested_rva, SymTagFunction, &symbol);
    if (FAILED(hr) || symbol == nullptr) {
        return false;
    }

    BSTR name_bstr = nullptr;
    BSTR source_bstr = nullptr;
    DWORD symbol_rva = 0;
    ULONGLONG length = 0;
    symbol->get_name(&name_bstr);
    symbol->get_sourceFileName(&source_bstr);
    symbol->get_relativeVirtualAddress(&symbol_rva);
    symbol->get_length(&length);

    summary.symbol_name = bstr_to_wstring(name_bstr);
    summary.direct_source_path = bstr_to_wstring(source_bstr);
    summary.has_direct_source = !summary.direct_source_path.empty();
    SysFreeString(name_bstr);
    SysFreeString(source_bstr);

    IDiaEnumLineNumbers *lines = nullptr;
    hr = session->findLinesByRVA(symbol_rva, static_cast<DWORD>(length), &lines);
    if (FAILED(hr) || lines == nullptr) {
        summary.has_line_info = false;
        summary.primary_source_path = summary.direct_source_path;
        summary.primary_source_file = basename_from_path(summary.primary_source_path);
        safe_release(symbol);
        return true;
    }

    std::set<std::wstring> unique_files;
    ULONG fetched = 0;
    DWORD line_start = 0;
    DWORD line_end = 0;
    bool have_line_range = false;
    std::wstring previous_path;
    DWORD previous_line = 0;
    bool have_previous = false;

    for (;;) {
        IDiaLineNumber *line = nullptr;
        fetched = 0;
        if (lines->Next(1, &line, &fetched) != S_OK || fetched != 1) {
            safe_release(line);
            break;
        }

        IDiaSourceFile *source_file = nullptr;
        BSTR file_bstr = nullptr;
        DWORD line_number = 0;
        DWORD line_rva = 0;
        if (SUCCEEDED(line->get_sourceFile(&source_file)) && source_file != nullptr) {
            source_file->get_fileName(&file_bstr);
        }
        line->get_lineNumber(&line_number);
        line->get_relativeVirtualAddress(&line_rva);

        std::wstring file_path = bstr_to_wstring(file_bstr);
        std::wstring file_name = basename_from_path(file_path);
        SysFreeString(file_bstr);

        if (!file_path.empty()) {
            unique_files.insert(file_path);
            summary.line_record_count += 1;
            if (!have_line_range) {
                line_start = line_number;
                line_end = line_number;
                have_line_range = true;
            } else {
                line_start = std::min(line_start, line_number);
                line_end = std::max(line_end, line_number);
            }

            if (!have_previous || file_path != previous_path || line_number != previous_line) {
                changes.push_back({line_rva + image_base, line_number, file_path, file_name});
                previous_path = file_path;
                previous_line = line_number;
                have_previous = true;
            }
        }

        safe_release(source_file);
        safe_release(line);
    }

    summary.has_line_info = summary.line_record_count != 0;
    summary.line_change_count = changes.size();
    summary.unique_file_count = unique_files.size();
    if (summary.has_line_info) {
        summary.line_start = line_start;
        summary.line_end = line_end;
        summary.primary_source_path = changes.front().source_path;
        summary.primary_source_file = changes.front().source_file;
    } else {
        summary.primary_source_path = summary.direct_source_path;
        summary.primary_source_file = basename_from_path(summary.primary_source_path);
    }

    safe_release(lines);
    safe_release(symbol);
    return true;
}

static void write_summary_csv(const wchar_t *path, const std::vector<FunctionSummary> &summaries) {
    std::ofstream out{std::filesystem::path(path), std::ios::binary};
    out << "va,symbol_name,direct_source_path,primary_source_path,primary_source_file,line_start,line_end,line_record_count,line_change_count,unique_file_count,has_line_info,has_direct_source\n";
    for (const FunctionSummary &summary : summaries) {
        out << csv_escape(hex8(summary.va)) << ','
            << csv_escape(utf8_from_wstring(summary.symbol_name)) << ','
            << csv_escape(utf8_from_wstring(summary.direct_source_path)) << ','
            << csv_escape(utf8_from_wstring(summary.primary_source_path)) << ','
            << csv_escape(utf8_from_wstring(summary.primary_source_file)) << ',';
        if (summary.has_line_info) {
            out << summary.line_start << ',' << summary.line_end << ',';
        } else {
            out << ",,";
        }
        out << summary.line_record_count << ','
            << summary.line_change_count << ','
            << summary.unique_file_count << ','
            << (summary.has_line_info ? "1" : "0") << ','
            << (summary.has_direct_source ? "1" : "0") << "\n";
    }
}

static void write_changes_csv(const wchar_t *path, const std::vector<std::pair<DWORD, LineChange>> &rows) {
    std::ofstream out{std::filesystem::path(path), std::ios::binary};
    out << "va,address,line_number,source_path,source_file\n";
    for (const auto &entry : rows) {
        out << csv_escape(hex8(entry.first)) << ','
            << csv_escape(hex8(entry.second.rva)) << ','
            << entry.second.line_number << ','
            << csv_escape(utf8_from_wstring(entry.second.source_path)) << ','
            << csv_escape(utf8_from_wstring(entry.second.source_file)) << "\n";
    }
}

int wmain(int argc, wchar_t **argv) {
    if (argc != 7) {
        std::wcerr << L"usage: pdb_function_source_export <msdia140.dll> <pdb> <image_base> <va_list.txt> <summary.csv> <changes.csv>\n";
        return 2;
    }

    HRESULT hr = CoInitialize(nullptr);
    if (FAILED(hr)) {
        std::wcerr << L"CoInitialize failed: 0x" << std::hex << hr << L"\n";
        return 1;
    }

    IDiaDataSource *data_source = nullptr;
    hr = NoRegCoCreate(argv[1], CLSID_DiaSource, __uuidof(IDiaDataSource), reinterpret_cast<void **>(&data_source));
    if (FAILED(hr) || data_source == nullptr) {
        std::wcerr << L"NoRegCoCreate failed: 0x" << std::hex << hr << L"\n";
        CoUninitialize();
        return 1;
    }

    hr = data_source->loadDataFromPdb(argv[2]);
    if (FAILED(hr)) {
        std::wcerr << L"loadDataFromPdb failed: 0x" << std::hex << hr << L"\n";
        safe_release(data_source);
        CoUninitialize();
        return 1;
    }

    IDiaSession *session = nullptr;
    hr = data_source->openSession(&session);
    if (FAILED(hr) || session == nullptr) {
        std::wcerr << L"openSession failed: 0x" << std::hex << hr << L"\n";
        safe_release(data_source);
        CoUninitialize();
        return 1;
    }

    wchar_t *image_base_end = nullptr;
    DWORD image_base = static_cast<DWORD>(wcstoul(argv[3], &image_base_end, 16));
    if (image_base_end == argv[3]) {
        std::wcerr << L"invalid image base: " << argv[3] << L"\n";
        safe_release(session);
        safe_release(data_source);
        CoUninitialize();
        return 1;
    }

    std::vector<DWORD> vas = load_rvas(argv[4]);
    std::vector<FunctionSummary> summaries;
    summaries.reserve(vas.size());
    std::vector<std::pair<DWORD, LineChange>> change_rows;

    for (DWORD va : vas) {
        FunctionSummary summary = {};
        std::vector<LineChange> changes;
        collect_function_source(session, image_base, va, summary, changes);
        summaries.push_back(summary);
        for (const LineChange &change : changes) {
            change_rows.push_back({va, change});
        }
    }

    write_summary_csv(argv[5], summaries);
    write_changes_csv(argv[6], change_rows);

    safe_release(session);
    safe_release(data_source);
    CoUninitialize();
    return 0;
}
