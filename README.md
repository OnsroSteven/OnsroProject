# OnsroProject

# PROJEK MENGIRIM DATA DARI ESP8266 ke GOOGLE SHEET

//Pada Projek Hari Ini Kita Akan Mencoba Menggunakan Google Sheet Sebagai Penerima Data Yang Dikirim Dari Pembacaan Sensor Oleh ESP ke Google Sheet
// Cara Kerja Dari Projek Ini Sederhana Berikut Urutan Kerjannya
//1. ESP8266 akan Menghubungkan Ke WiFi dengan Internet
//2. Data atau Status Dari Sensor Akan Dibaca Oleh ESP8266
//3. Sensor Membaca Keadaan Di Sekitarnnya
//4. Data Yang Telah Diterima Akan Dikirimkan Ke [Link_Google_Sheet] + [?value1=] + [nilaiSensor1] + [&value2=] + [nilaiSensor2] + [&value3=] + [nilaiSensor3]
//5. Google Script Akan Menerima Nilai Dari Sensor dan di-_input_kan ke Google Sheet
//6. Kita dapat mengelola data yang terdapat pada Google sheet.
