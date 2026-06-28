# Arduino IDE

Arduino IDE is used to write, compile, and upload sketches to the ESP32-S3 development board.

For this programme, Arduino IDE is a useful starting point because it is simple to install and allows students to test hardware quickly without needing a complex development environment.

## What You Need

Before starting, make sure you have:

* A computer with internet access
* A USB-C data cable
* A Tenstar ESP32-S3 development board
* Arduino IDE installed
* ESP32 board support installed
* The required Arduino libraries installed

!!! tip

    Use a USB cable that supports data. Some USB-C cables are charge-only. They may power the board, but they will not allow code upload.

## Installing Arduino IDE

Download Arduino IDE from the official Arduino installation guide:

<a href="https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE" target="_blank" rel="noopener noreferrer">Download and install Arduino IDE</a>

General installation steps:

1. Download the latest Arduino IDE for your operating system.
2. Install it using the default options.
3. Open Arduino IDE.
4. Allow any first-time setup prompts to finish.
5. Connect the ESP32-S3 board using USB-C.

Arduino IDE is now installed, but ESP32 board support still needs to be added.

## Adding ESP32 Board Support

The Tenstar board uses an ESP32-S3 microcontroller. Arduino IDE needs the ESP32 board package before it can compile and upload code for this board.

Open:

```text
File → Preferences
```

Find:

```text
Additional boards manager URLs
```

Add this URL:

```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Useful reference:

<a href="https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html" target="_blank" rel="noopener noreferrer">Espressif Arduino-ESP32 installation guide</a>

Click **OK**.

## Installing the ESP32 Board Package

Open:

```text
Tools → Board → Boards Manager
```

Search for:

```text
esp32
```

Install the package by:

```text
Espressif Systems
```

After installation, restart Arduino IDE if the ESP32 boards do not appear in the board list.

## Selecting the Board

Go to:

```text
Tools → Board → ESP32 Arduino
```

Select:

```text
ESP32S3 Dev Module
```

Use these settings in the **Tools** menu as a starting point:

| Setting         | Value                                |
| --------------- | ------------------------------------ |
| Board           | ESP32S3 Dev Module                   |
| USB CDC On Boot | Enabled                              |
| USB Mode        | Hardware CDC and JTAG                |
| Upload Mode     | UART0 / Hardware CDC                 |
| Upload Speed    | 921600                               |
| PSRAM           | Disabled unless needed               |
| Port            | The COM port for the connected board |

!!! note

        The exact port number may be different on each computer. On Windows it may appear as `COM3`, `COM4`, or another COM number. The port can also be checked using Device Manager or the `mode` command in Command Prompt.

## Installing Required Libraries

Open:

```text
Sketch → Include Library → Manage Libraries
```

Arduino library reference:

<a href="https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE" target="_blank" rel="noopener noreferrer">Add libraries to Arduino IDE</a>

Search for and install the libraries required by the examples used in this programme.

| Library                            | Purpose                                          |
| ---------------------------------- | ------------------------------------------------ |
| Adafruit GFX Library               | Drawing graphics on displays                     |
| Adafruit ST7735 and ST7789 Library | Using ST7735/ST7789 TFT displays                 |
| Adafruit BMP280 Library            | Reading pressure and temperature from the BMP280 |
| SensorLib                          | Working with sensors such as the QMI8658C IMU    |
| TinyGPSPlus                        | Parsing GNSS NMEA messages                       |
| Adafruit NeoPixel                  | Controlling RGB LEDs                             |

If Arduino IDE asks to install dependencies, choose **Install All**.

## Uploading a First Test Sketch

Before connecting extra sensors or GNSS modules, upload a simple test sketch first.

Arduino upload reference:

<a href="https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE" target="_blank" rel="noopener noreferrer">Upload a sketch in Arduino IDE</a>

This confirms that:

* The board package is installed
* The correct board is selected
* The port is working
* The USB cable supports data
* Code can be uploaded successfully

Use this simple Serial Monitor test:

```cpp
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32-S3 test upload successful");
}

void loop() {
  Serial.println("Board is running");
  delay(1000);
}
```

Open the Serial Monitor and set the baud rate to:

```text
115200
```

If the message appears repeatedly, the board is working.

## If Uploading Fails

If the upload does not work, try these checks:

| Problem                           | Possible Fix                                      |
| --------------------------------- | ------------------------------------------------- |
| No port appears                   | Try another USB cable or USB port                 |
| Upload times out                  | Hold **BOOT**, press **RESET**, then upload again |
| Serial Monitor is blank           | Check that the baud rate is set to `115200`       |
| Wrong board selected              | Select `ESP32S3 Dev Module`                       |
| Board is powered but not detected | Use a known data-capable USB cable                |

!!! warning
        
        Do not connect extra modules until a basic upload test works. It is easier to solve one problem at a time.

## Working With Arduino Sketches From GitHub

For team projects, Arduino sketches should be stored inside the repository.

A useful structure is:

```text
code/
├── BlinkTest/
│   └── BlinkTest.ino
├── GNSS_Raw_NMEA/
│   └── GNSS_Raw_NMEA.ino
└── TinyGPSPlus_Test/
    └── TinyGPSPlus_Test.ino
```

Arduino IDE expects the folder name and `.ino` file name to match.

Correct:

```text
TinyGPSPlus_Test/TinyGPSPlus_Test.ino
```

Avoid:

```text
TinyGPSPlus_Test/test.ino
```

## Recommended Workflow

Use this routine when editing Arduino code:

```text
Pull latest changes → Open sketch → Test upload → Save → Commit → Push
```

Arduino IDE edits local files on the computer. Git, GitHub Desktop, or another Git tool is then used to upload those saved changes to GitHub.
