from pathlib import Path

STOP_WORDS  = ["o", "a", "os", "as", "um", "uma", "e", "ou", "de", "da", "do", "em", "no", "na", "para", "com"]

#Recebe o caminho da pasta data

BASE_DIR = Path(__file__).resolve().parent.parent

DATA_DIR = BASE_DIR / "data"

OBJ_FILE_PATH = DATA_DIR / "resultado.json"

