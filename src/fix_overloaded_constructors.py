import os
import re

# ================= CONFIGURATION =================
# Folder containing the files with BROKEN overloads
GAME_FOLDER_PATH = r"game"

# Folder containing the files with FIXED bodies
FIXED_FOLDER_PATH = r"C:\Users\Darius\ghidra_scripts\Decompilation_Export"
# =================================================

# Regex to match function definitions like:
# void ClassName::FuncName(
# MyClass::MyClass(
# int Class::DoSomething(
# It captures "ClassName::FuncName" in group 1.
FUNC_DEF_PATTERN = re.compile(r'^\s*(?:[\w\:<>*&]+\s+)*(\w+::[~\w]+)\s*\(')

def strip_comments_for_parsing(line):
    """
    Helper to remove C++ comments from a line for brace counting purposes.
    """
    if "//" in line:
        line = line.split("//")[0]
    line = re.sub(r'/\*.*?\*/', '', line)
    return line

def find_closing_brace(lines, start_index):
    """
    Finds the closing brace '}' for a block starting at start_index.
    """
    brace_level = 0
    found_first_brace = False
    
    for i in range(start_index, len(lines)):
        line = lines[i]
        clean_line = strip_comments_for_parsing(line)
        
        open_braces = clean_line.count('{')
        close_braces = clean_line.count('}')
        
        if open_braces > 0:
            found_first_brace = True
            
        brace_level += (open_braces - close_braces)
        
        if found_first_brace and brace_level == 0:
            return i
            
    return len(lines) - 1

def parse_functions(lines):
    """
    Scans a list of lines. Returns a dictionary grouping functions by name.
    
    Returns:
    {
        'ClassName::FuncName': [
            {'start': 10, 'end': 25},
            {'start': 28, 'end': 40}
        ],
        ...
    }
    """
    functions = {}

    for i, line in enumerate(lines):
        # Skip pure comment lines to avoid false positives in commented out code
        if line.strip().startswith("//"):
            continue

        match = FUNC_DEF_PATTERN.match(line)
        if match:
            func_name = match.group(1)
            end_line = find_closing_brace(lines, i)
            
            if func_name not in functions:
                functions[func_name] = []
            
            functions[func_name].append({
                'start': i,
                'end': end_line
            })

    return functions

def process_files():
    if not os.path.exists(GAME_FOLDER_PATH) or not os.path.exists(FIXED_FOLDER_PATH):
        print("Error: One or both folder paths are invalid.")
        return

    print(f"Scanning '{GAME_FOLDER_PATH}' for overloaded functions...")

    for filename in os.listdir(GAME_FOLDER_PATH):
        if not filename.endswith(".cpp"):
            continue

        game_file_path = os.path.join(GAME_FOLDER_PATH, filename)
        fixed_file_path = os.path.join(FIXED_FOLDER_PATH, filename)

        # Skip if no fix file exists
        if not os.path.exists(fixed_file_path):
            continue

        # 1. Analyze the GAME file
        with open(game_file_path, 'r', encoding='utf-8', errors='ignore') as f:
            game_lines = f.readlines()
        
        game_funcs = parse_functions(game_lines)
        
        # Identify names that are overloaded (appear > 1 time)
        overloaded_names = [name for name, locations in game_funcs.items() if len(locations) > 1]

        if not overloaded_names:
            continue

        # 2. Analyze the FIXED file
        try:
            with open(fixed_file_path, 'r', encoding='utf-8', errors='ignore') as f:
                fixed_lines = f.readlines()
            fixed_funcs = parse_functions(fixed_lines)
        except Exception as e:
            print(f"Error reading fixed file {filename}: {e}")
            continue

        # 3. Calculate Replacements
        # We store replacements as tuples: (start_line_in_game, end_line_in_game, new_content_lines)
        replacements = []

        for func_name in overloaded_names:
            # Check if this function exists in the fixed file
            if func_name not in fixed_funcs:
                print(f"WARNING: {filename} -> '{func_name}' is overloaded in game/ but missing in fixed/. Skipping this function.")
                continue

            # Get ranges in Broken File
            g_ranges = game_funcs[func_name]
            g_ranges.sort(key=lambda x: x['start'])
            g_start = g_ranges[0]['start']
            g_end = g_ranges[-1]['end']

            # Get ranges in Fixed File
            f_ranges = fixed_funcs[func_name]
            f_ranges.sort(key=lambda x: x['start'])
            f_start = f_ranges[0]['start']
            f_end = f_ranges[-1]['end']

            # Extract content from Fixed File
            # +1 to include the closing brace line
            new_chunk = fixed_lines[f_start : f_end + 1]

            replacements.append({
                'name': func_name,
                'start': g_start,
                'end': g_end,
                'content': new_chunk
            })

        if not replacements:
            continue

        # 4. Apply Replacements
        # IMPORTANT: Sort by start index DESCENDING. 
        # By replacing from the bottom of the file up, we don't mess up the line indices 
        # for the replacements that occur earlier in the file.
        replacements.sort(key=lambda x: x['start'], reverse=True)

        modified = False
        current_lines = list(game_lines) # Make a copy to work on

        for rep in replacements:
            start = rep['start']
            end = rep['end']
            content = rep['content']
            
            # Check for overlap safety (simple check)
            # Since we replace the whole block from first overload to last overload,
            # we just swap list slice.
            
            # Replaces lines [start ... end] (inclusive) with content
            current_lines[start : end + 1] = content
            modified = True
            print(f"FIXED: {filename} -> Replaced overloads for '{rep['name']}'")

        # 5. Write back if modified
        if modified:
            try:
                with open(game_file_path, 'w', encoding='utf-8') as f:
                    f.writelines(current_lines)
            except Exception as e:
                print(f"ERROR writing {filename}: {e}")

if __name__ == "__main__":
    process_files()