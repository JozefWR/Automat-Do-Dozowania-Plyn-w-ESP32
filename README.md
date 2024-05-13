# Automat do Dozowania Płynów z Obsługą Zdalną (ESP32_BT)

## Opis projektu

Automat do dozowania płynów z możliwością obsługi zdalnej to zaawansowany projekt inżynierski, który łączy w sobie elektronikę i programowanie do stworzenia zintegrowanego systemu sterowania. Projekt został wykonany na Politechnice Koszalińskiej jako praca dyplomowa.

## Instalacja i konfiguracja

1. Sklonuj to repozytorium na swoje lokalne środowisko.
2. Zapoznaj się z dokumentacją techniczną zawartą w pliku `praca_inzynierska.pdf` dla szczegółów dotyczących budowy i działania urządzenia.
3. Zainstaluj wymagane oprogramowanie i biblioteki, jak opisano w dokumentacji.

## Schematy montażu i testowania

Nazwy elementów, moduły, zdjęcia i schematy montażu oraz testowania znajdują się w pliku `praca_inzynierska.pdf`. Wizualizacje te pomogą w zrozumieniu dokładnego procesu składania urządzenia i jego konfiguracji.

## Programowanie

Programowanie mikrokontrolera ESP32 odbywa się przez Arduino IDE. Kod źródłowy oraz szczegółowe instrukcje znajdują się w folderze i pliku `program_ESP32`.

## Zdjęcia i rysunki

- ![GotowyPrototyp](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/5b333fad-190b-4b60-9f7c-c1099c986f4d) - zdjęcie gotowego prototypu urządzenia.
- ![SchematKomunikacji](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/8200e662-ff32-4332-ba02-6b75b772492b) - schemat komunikacji.
- ![SchematPłytkiPCB](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/8c2ad312-b27e-4db1-a027-e2b8983675ef) - schemat elektroniczny płytki PCB.
- ![PłytkaPCB](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/f8e3cc00-c75b-469e-915d-de885dfafb54)
 - płytka PCB.
- ![SchematBlokowy](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/b0a59585-bd0c-4783-b69f-e1120cb3fce2) - schemat blokowy działania automatu.
- ![Menu](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/1aca6d07-5380-45b4-a79e-a5ed38c9f81d)
  ![Tarowanie](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/ca57ddc7-62d9-475e-b5d8-a1d9cf30802c)
  ![Nalewanie](https://github.com/JozefWR/Automat-Do-Dozowania-Plyn-w-ESP32/assets/166382259/a1478d8d-dbb1-456a-8f94-0123187eb7a3)
- zrzuty ekranu z aplikacji mobilnej.

## Wykorzystane technologie

Projekt wykorzystuje następujące technologie:
- **Mikrokontroler ESP32**: Serce systemu, odpowiada za sterowanie działaniem urządzenia i komunikację zdalną.
- **Arduino IDE**: Środowisko programistyczne używane do pisania kodu dla mikrokontrolera.
- **Eagle CAD**: Oprogramowanie do projektowania płytek PCB, używane do tworzenia schematów elektronicznych i layoutów PCB.
- **Technologie mobilne**: Aplikacja mobilna umożliwia zdalne sterowanie urządzeniem i monitorowanie jego stanu.
- **Bluetooth**: Komunikacja bezprzewodowa między mikrokontrolerem a aplikacją mobilną.
