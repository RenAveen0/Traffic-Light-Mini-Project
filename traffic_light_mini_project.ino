// UTARA
int u_merah = 2;
int u_kuning = 3;
int u_hijau = 4;

// TIMUR
int t_merah = 5;
int t_kuning = 6;
int t_hijau = 7;

// SELATAN
int s_merah = 8;
int s_kuning = 9;
int s_hijau = 10;

// BARAT
int b_merah = 11;
int b_kuning = 12;
int b_hijau = 13;

void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  semuaMerah();
  digitalWrite(u_merah, LOW);
  digitalWrite(u_hijau, HIGH);
  delay(5000);

  transisi(u_kuning, t_kuning, u_hijau, u_merah, t_merah);
  digitalWrite(u_merah, HIGH);
  digitalWrite(t_merah, LOW);
  digitalWrite(t_hijau, HIGH);

  delay(5000);

  transisi(t_kuning, s_kuning, t_hijau, t_merah, s_merah);
  digitalWrite(t_merah, HIGH);
  digitalWrite(s_merah, LOW);
  digitalWrite(s_hijau, HIGH);

  delay(5000);

  transisi(s_kuning, b_kuning, s_hijau, s_merah, b_merah);
  digitalWrite(s_merah, HIGH);
  digitalWrite(b_merah, LOW);
  digitalWrite(b_hijau, HIGH);

  delay(5000);

  transisi(b_kuning, u_kuning, b_hijau, b_merah, u_merah);
  digitalWrite(b_merah, HIGH);
  digitalWrite(u_merah, LOW);
  digitalWrite(u_hijau, HIGH);
}

void semuaMerah() {
  digitalWrite(u_merah, HIGH);
  digitalWrite(u_kuning, LOW);
  digitalWrite(u_hijau, LOW);

  digitalWrite(t_merah, HIGH);
  digitalWrite(t_kuning, LOW);
  digitalWrite(t_hijau, LOW);

  digitalWrite(s_merah, HIGH);
  digitalWrite(s_kuning, LOW);
  digitalWrite(s_hijau, LOW);

  digitalWrite(b_merah, HIGH);
  digitalWrite(b_kuning, LOW);
  digitalWrite(b_hijau, LOW);
}

void transisi(int dari_kuning, int ke_kuning, int dari_hijau, int dari_merah, int ke_merah) {

  digitalWrite(dari_hijau, LOW);

  digitalWrite(dari_merah, LOW);
  digitalWrite(ke_merah, LOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(dari_kuning, HIGH);
    digitalWrite(ke_kuning, HIGH);
    delay(300);

    digitalWrite(dari_kuning, LOW);
    digitalWrite(ke_kuning, LOW);
    delay(300);
  }

  digitalWrite(dari_kuning, HIGH);
  digitalWrite(ke_kuning, HIGH);
  delay(2000);

  digitalWrite(dari_kuning, LOW);
  digitalWrite(ke_kuning, LOW);
}