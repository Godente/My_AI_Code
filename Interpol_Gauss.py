import numpy as np                        #importa libreria per il calcolo matematico e chiamalo np, che sarà un oggetto 
import matplotlib.pyplot as plt           #importa librerie per i plot 
from tensorflow import keras              #tensorflow è l'insieme di funzioni a basso livello e oggetti utilizzati per machine learning, keras semplifica ed è utile per principianti 
from tensorflow.keras import layers       #importo gli oggetti (strutture dati) da keras

# Generazione di un dataset di esempio
# Creiamo 100 punti equidistanti tra -1 e 1
x = np.linspace(-1, 1, 100)
# Funzione target (ad esempio, una sinusoide)
y = np.sin(np.pi * x)

# Aggiungiamo del rumore ai dati
noise = 0.1 * np.random.normal(size=y.shape)
y_noisy = y + noise                         

# Creazione del modello della rete neurale
model = keras.Sequential([
    # 5 neuroni con attivazione tangente iperbolica
    layers.Dense(5, activation='tanh', input_shape=(1,)),  # strato nascosto
    # 1 neurone di output senza attivazione
    layers.Dense(1)                                        # strato di output
])

# Compilazione del modello
model.compile(optimizer='adam', loss='mean_squared_error')

# Addestramento del modello
model.fit(x, y_noisy, epochs=1000, verbose=1) #verbose 0 non dice niente nell terminal più veloce

# Predizione sui dati di input (Inferenza)
y_pred = model.predict(x)

# Visualizzazione dei risultati
plt.figure(figsize=(10, 6))
plt.scatter(x, y_noisy, label='Dati con rumore', color='blue', alpha=0.5)
plt.plot(x, y, label='Funzione originale (sin)', color='green', linewidth=2)
plt.plot(x, y_pred, label='Predizione della rete neurale', color='red', linewidth=2)
plt.title('Interpolazione con Rete Neurale Feedforward')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid()
plt.show()
