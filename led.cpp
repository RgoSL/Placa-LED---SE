// Aqui é definido os valores dos LEDs
const int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0}; // Temos 13 LEDs em questão

// Aqui é uma Matriz que mapea, conforme o número digitado, qual é o padrão que deve ser acesso ou desligado.
const int mapPins[][13] = {
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 2
    {1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 3
    {0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, // 5
    {1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 6
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}  // 9
};

void setup() {
    // Aqui ocorre a transformação dos valores para a exibição na placa.
    for (int i = 0; i < 13; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW); // Inicia com os LEDs desligados.
    }

    Serial.begin(9600);
    Serial.println("Digite um número (0-9):");
}


void loop() {
    if (Serial.available()) {
        int num = Serial.parseInt(); //A váriavel "num" é a que recebe o valor de entrada.
        if (num >= 0 && num <= 9) {
            for (int i = 0; i < 13; i++) {
                digitalWrite(ledPins[i], mapPins[num][i]);  //Num é passada para a matriz mapPins, e o programa procura seu valor dentro dela.
            }
        }
        Serial.println("Digite um número (0-9):");
    }
}
