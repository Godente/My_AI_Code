import re

def rimuovi_timestamp(input_file, output_file):
    # Espressione regolare per il timestamp
    pattern = r"\[\d{2}:\d{2}:\d{2}.\d{3} - \d{2}:\d{2}:\d{2}.\d{3}\]"

    # Apre il file di input e legge il contenuto
    with open(input_file, 'r', encoding='utf-8') as file:
        contenuto = file.read()

    # Rimuove tutti i timestamp trovati
    contenuto_pulito = re.sub(pattern, '', contenuto)

    # Scrive il contenuto ripulito in un nuovo file di output
    with open(output_file, 'w', encoding='utf-8') as file:
        file.write(contenuto_pulito)

# Esempio di utilizzo
input_file = '/Users/god/Downloads/MTAI 4.txt'  # Sostituisci con il tuo file di input
output_file = '/Users/god/Downloads/MTAI 42.txt'  # Sostituisci con il file di output desiderato
rimuovi_timestamp(input_file, output_file)
