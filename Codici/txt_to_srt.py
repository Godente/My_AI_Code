import re
import os

def convert_txt_to_srt(input_file):
    
    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    srt_lines = []
    index = 1
    
    for line in lines:
        match = re.match(r"\[(\d{2}:\d{2}:\d{2}\.\d{3}) - (\d{2}:\d{2}:\d{2}\.\d{3})\]", line)
        if match:
            start_time = match.group(1).replace('.', ',')
            end_time = match.group(2).replace('.', ',')

            srt_lines.append(f"{index}\n{start_time} --> {end_time}\n")
            index += 1
        else:
            srt_lines.append(line)

            
    # Crea il percorso del file di output
    base_name = os.path.splitext(os.path.basename(input_file))[0] #evita name.txt.srt
    dir_name = os.path.dirname(input_file)
    srt_file = os.path.join(dir_name, f"{base_name}.srt")

    with open(srt_file, 'w', encoding='utf-8') as f:
        f.writelines(srt_lines)

    print(f"Conversione di {base_name} riuscita")

def convert_multitxt_to_srt(path_files, input_files):

    for i in input_files:
            
     input_file = os.path.join(path_files, i)
     convert_txt_to_srt(input_file)   


#### main ####
print("\nEnjoy is gonna help you to convert timpestamped txt files in srt.\n"
"In case of multiple files they should be in the same folder")
ask = input("Do you wanna edit multiple files (y or n)?: ")
if ask == "n":
    input_file = input("Paste the file's path: ")
    convert_txt_to_srt(input_file)
elif ask == "y":
      path_files = input("Paste the path of folder: ")
      user_input = input("Digit the file's names only splited by a coma(ex. file 1,file 2): ")
      input_files = [
          f"{nome.strip()}.txt" 
          for nome in user_input.split(',')]
      convert_multitxt_to_srt(path_files,input_files)
else:
    print("Invalid input. Please enter 'y' or 'n'.")