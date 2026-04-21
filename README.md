# InternFCS

InternFCS is an iOS mobile application designed to aggregate and streamline the internship search process for IT students. The project features a hybrid architecture that combines the high-performance data processing of **C++** with the modern, declarative user interface of **SwiftUI**.

## Features

* **Hybrid Core (C++/Swift):** Leverages C++ for business logic and data management to achieve native execution speeds, while SwiftUI provides a fluid and responsive user experience.
* **Performance-First Parsing:** Features a custom-built C++ parser optimized for flat-file databases, ensuring near-instant loading and indexing of internship records.
* **Objective-C++ Bridge:** Implements a robust mediation layer (Bridge) that safely translates complex C++ data structures into native Apple Foundation objects.
* **Smart Filtering:** Includes a dynamic filtering system by categories (Backend, ML, Mobile, Security, etc.) and real-time "Favorites" synchronization.

## Installation

### Prerequisites
* macOS running Xcode 15.0 or later.
* Xcode Command Line Tools installed.

### Setup
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/InternFCS.git](https://github.com/your-username/InternFCS.git)
    cd InternFCS
    ```
2.  **Open the project:** Launch `InternFCS.xcodeproj` in Xcode.
3.  **Link Resources:** Ensure the `internships.txt` file is included in the project hierarchy and its **Target Membership** is checked in the File Inspector.

## Usage

1.  **Launch:** Press `Cmd + R` in Xcode to deploy the app to a simulator or a physical device.
2.  **Browse:** The main screen displays a comprehensive list of available internships loaded from the local database.
3.  **Filter:** Use the segmented picker at the top to filter roles by tech stack (e.g., "ML" or "Backend").
4.  **Favorites:** Tap the heart icon on any internship card to save it. The state is instantly synced between the C++ core and the UI.
5.  **Details:** Each card provides a direct link to the application page and displays the specific application deadline.

## Technical Background

This project explores the integration of high-level UI frameworks with system-level programming languages. Key technical challenges addressed include:
* **Memory Management:** Efficient use of STL containers (`std::unordered_map`, `std::vector`) to manage `Internship` and `User` objects.
* **Type Safety:** Seamless type conversion between `std::string` and `NSString`, and handling `std::unordered_set` through the Objective-C++ bridge.
* **State Synchronization:** Binding SwiftUI views to changes in C++ objects using delegation patterns and bridge interfaces.
