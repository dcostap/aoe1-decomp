import os
import re

# Hardcoded folder path
FOLDER_PATH = r"game"

# Regex to match C++ constructor patterns like Foo::Foo
pattern = re.compile(r'\b([A-Za-z_]\w*)::\1\b')

def find_files_with_repeated_constructors(folder_path):
    for filename in os.listdir(folder_path):
        path = os.path.join(folder_path, filename)
        if not os.path.isfile(path):
            continue  # skip directories

        try:
            with open(path, 'r', encoding='utf-8', errors='ignore') as f:
                lines = f.readlines()

            # Remove lines starting with comment markers (ignoring leading whitespace)
            code_lines = [
                line for line in lines
                if not line.strip().startswith("//")
            ]

            content = "".join(code_lines)
            matches = pattern.findall(content)

            # Count how many times each constructor name appears
            counts = {}
            for name in matches:
                counts[name] = counts.get(name, 0) + 1

            # Check if any constructor appears more than twice
            repeated = [name for name, count in counts.items() if count > 1]
            if repeated:
                print(f"{filename} -> repeated constructors: {', '.join(repeated)}")

        except Exception as e:
            print(f"Error reading {filename}: {e}")

if __name__ == "__main__":
    find_files_with_repeated_constructors(FOLDER_PATH)
