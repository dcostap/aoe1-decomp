import os
import re

# ================= CONFIGURATION =================
# Folder containing the files with BROKEN constructors
GAME_FOLDER_PATH = r"game"

# Folder containing the files with FIXED constructors
FIXED_FOLDER_PATH = r"C:\Users\Darius\ghidra_scripts\Decompilation_Export"
# =================================================

# Regex to match the definition start: ClassName::ClassName(
# Anchored to start of line (allowing whitespace) to avoid matching function calls inside other functions.
CTOR_DEF_PATTERN = re.compile(r'^\s*([A-Za-z_]\w*)::\1\s*\(')

def strip_comments_for_parsing(line):
    """
    Simple helper to remove C++ comments from a line for brace counting purposes.
    Note: This is a lightweight approach. It handles // and simple /* */.
    It does not perfectly handle complex strings containing comment markers.
    """
    # Remove single line comments
    if "//" in line:
        line = line.split("//")[0]
    
    # Remove block comments (inline only for this simple line-by-line logic)
    # A full C++ parser is complex, but this covers 99% of decompiled output.
    line = re.sub(r'/\*.*?\*/', '', line)
    return line

def find_closing_brace(lines, start_index):
    """
    Given a list of lines and a start index (where a function definition begins),
    find the line index of the closing brace '}'.
    Returns the index of the closing line.
    """
    brace_level = 0
    found_first_brace = False
    
    for i in range(start_index, len(lines)):
        line = lines[i]
        
        # We strip comments to avoid counting braces inside comments
        clean_line = strip_comments_for_parsing(line)
        
        # Count braces
        open_braces = clean_line.count('{')
        close_braces = clean_line.count('}')
        
        if open_braces > 0:
            found_first_brace = True
            
        brace_level += (open_braces - close_braces)
        
        # If we have started the block and returned to level 0, we are done
        if found_first_brace and brace_level == 0:
            return i
            
    return len(lines) - 1 # Fallback (should shouldn't happen in valid C++)

def analyze_file_constructors(filepath):
    """
    Parses a CPP file.
    Returns a dictionary:
    {
        'ClassName': [
            {'start': int, 'end': int},
            {'start': int, 'end': int}
        ],
        ...
    }
    """
    if not os.path.exists(filepath):
        return None

    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    constructors = {}

    for i, line in enumerate(lines):
        match = CTOR_DEF_PATTERN.match(line)
        if match:
            class_name = match.group(1)
            end_line = find_closing_brace(lines, i)
            
            if class_name not in constructors:
                constructors[class_name] = []
            
            constructors[class_name].append({
                'start': i,
                'end': end_line
            })

    return lines, constructors

def process_overloaded_constructors():
    if not os.path.exists(GAME_FOLDER_PATH) or not os.path.exists(FIXED_FOLDER_PATH):
        print("Error: One or both folder paths are invalid.")
        return

    print(f"Scanning '{GAME_FOLDER_PATH}' for overloaded constructors...")

    for filename in os.listdir(GAME_FOLDER_PATH):
        if not filename.endswith(".cpp"):
            continue

        game_file_path = os.path.join(GAME_FOLDER_PATH, filename)
        
        # 1. Analyze the GAME file
        game_lines, game_ctors = analyze_file_constructors(game_file_path)
        
        # Identify classes with overloaded constructors (count > 1)
        classes_with_overloads = [
            cls for cls, ranges in game_ctors.items() 
            if len(ranges) > 1
        ]

        # 2. Check Constraint: More than one class has overloads?
        if len(classes_with_overloads) > 1:
            print(f"SKIP [Multiple Classes]: {filename} has overloaded constructors for multiple classes: {', '.join(classes_with_overloads)}")
            continue

        if not classes_with_overloads:
            # No overloaded constructors found, skip file
            continue

        target_class = classes_with_overloads[0]
        
        # 3. Check for existence in FIXED folder
        fixed_file_path = os.path.join(FIXED_FOLDER_PATH, filename)
        if not os.path.exists(fixed_file_path):
            print(f"SKIP [Missing Fixed]: {filename} has overloads but no corresponding file found in {FIXED_FOLDER_PATH}")
            continue

        # 4. Analyze the FIXED file
        fixed_lines, fixed_ctors = analyze_file_constructors(fixed_file_path)

        if target_class not in fixed_ctors:
            print(f"SKIP [Missing Class]: {filename} found in fixed folder, but class '{target_class}' not found inside.")
            continue

        # 5. Determine Ranges
        
        # GAME Range: From start of first overload to end of last overload
        game_ranges = game_ctors[target_class]
        # Sort just in case logic processed out of order, though file read is sequential
        game_ranges.sort(key=lambda x: x['start'])
        
        game_start_idx = game_ranges[0]['start']
        game_end_idx = game_ranges[-1]['end']

        # FIXED Range: From start of first constructor to end of last constructor for that class
        # (Assuming we replace the whole set of constructors with the fixed set)
        fixed_ranges = fixed_ctors[target_class]
        fixed_ranges.sort(key=lambda x: x['start'])
        
        fixed_start_idx = fixed_ranges[0]['start']
        fixed_end_idx = fixed_ranges[-1]['end']

        # 6. Perform Substitution
        # Construct new file content
        new_content = []
        
        # Part A: Everything before the constructors in GAME file
        new_content.extend(game_lines[:game_start_idx])
        
        # Part B: The constructors from the FIXED file (inclusive)
        # +1 because slice end is exclusive
        new_content.extend(fixed_lines[fixed_start_idx : fixed_end_idx + 1])
        
        # Part C: Everything after the constructors in GAME file
        new_content.extend(game_lines[game_end_idx + 1:])

        # 7. Write Result
        try:
            with open(game_file_path, 'w', encoding='utf-8') as f:
                f.writelines(new_content)
            print(f"FIXED: {filename} -> Replaced constructors for '{target_class}'")
        except Exception as e:
            print(f"ERROR writing {filename}: {e}")

if __name__ == "__main__":
    process_overloaded_constructors()