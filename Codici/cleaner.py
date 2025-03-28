import re
import os

def rimuovi_timestamp(input_file):
    # Rimuove le virgolette eventuali attorno al percorso
    input_file = input_file.strip('"')

    # Espressione regolare per rimuovere i timestamp e le righe vuote
    pattern = r"\[\d{2}:\d{2}:\d{2}.\d{3} - \d{2}:\d{2}:\d{2}.\d{3}\]"

    # Apre il file di input e legge il contenuto
    with open(input_file, 'r', encoding='utf-8') as file:
        contenuto = file.read()

    # Rimuove i timestamp
    contenuto_pulito = re.sub(pattern, '', contenuto)

    # Rimuove le righe vuote e assicura che ci sia solo una riga vuota tra le frasi
    contenuto_pulito = re.sub(r'\n\s*\n', '\n', contenuto_pulito)

    # Crea il percorso del file di output con "clean" nel nome
    base_name = os.path.basename(input_file)
    dir_name = os.path.dirname(input_file)
    output_file = os.path.join(dir_name, f"clean_{base_name}")

    # Scrive il contenuto ripulito in un nuovo file di output
    with open(output_file, 'w', encoding='utf-8') as file:
        file.write(contenuto_pulito)

    print(f"- {base_name} is clean")

def multirimuovi_timestamp(path_files,input_files):
   for i in input_files:
            
     input_file = os.path.join(path_files, i)
     rimuovi_timestamp(input_file)   



#### main ####
print("\nEnjoy is gonna help you to remove timpestamps and void lines.\n"
"In case of multiple txt-files they should be in the same folder")
ask = input("Do you wanna clean multiple files (y or n)?: ")
if ask == "n":
    input_file = input("Paste the file's path: ")
    rimuovi_timestamp(input_file)
elif ask == "y":
      path_files = input("Paste the path of folder: ")
      user_input = input("Digit the file's names only splited by a coma(ex. file 1,file 2): ")
      input_files = [
          f"{nome.strip()}.txt" 
          for nome in user_input.split(',')]
      multirimuovi_timestamp(path_files,input_files)
else:
    print("Invalid input. Please enter 'y' or 'n'.")