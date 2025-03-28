import re
import os

def convert_txt_to_srt(input_file):
    

    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    srt_lines = []
    index = 1
    
    for line in lines:
        match = re.match(r"\[(\d{2}:\d{2}:\d{2}\.\d{3}) - (\d{2}:\d{2}:\d{2}\.\d{3})\]\s*(.*)", line)
        if match:
            start_time = match.group(1).replace('.', ',')
            end_time = match.group(2).replace('.', ',')
            text = match.group(3)

            srt_lines.append(f"{index}\n{start_time} --> {end_time}\n{text}\n")
            index += 1

    # Crea il percorso del file di output
    base_name = os.path.splitext(os.path.basename(input_file))[0] #evita name.txt.srt
    dir_name = os.path.dirname(input_file)
    srt_file = os.path.join(dir_name, f"{base_name}.srt")

    with open(srt_file, 'w', encoding='utf-8') as f:
        f.writelines(srt_lines)

    print(f"Conversione riuscita")


# Usa il nome del tuo file di input e output
input_file = input("Inserisci il percorso del file di input: ")
convert_txt_to_srt(input_file)
