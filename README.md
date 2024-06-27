# Saksy Song Playlist Maker
Welcome to the Saksy Song Playlist maker! This application allows you to create, view, update, and manage a playlist of songs. You can insert, remove, search, and display songs in various ways, including shuffled and sorted orders.
## Features
- **Insert a Song**: Add a new song to the playlist.
- **Remove a Song**: Remove an existing song by its index.
- **Search Songs**: Search for songs by artist or album.
- **Display Playlist**: View the playlist in the default, shuffled, or sorted order.
- **Microservice Integration**: Shuffle or sort the playlist using a microservice.
## File Structure
- `main.cpp`: Contains the main logic for the CLI and playlist operations.
- `main.h`: Header file for main.cpp.
- `Song.cpp`: Contains the implementation of song operations like read, save, shuffle, sort, etc.
- `Song.h`: Header file for Song.cpp.
- `microservice.py`: The microservice that handles shuffling and sorting of the playlist.
- `songs.txt`: The input file containing the list of songs.
- `order.txt`: The file used for commands to shuffle or sort the playlist.
## How to Use
1. **Run the Program**: 
    ```bash
    g++ main.cpp Song.cpp -o playlist
    ./playlist
    ```
2. **Menu Options**:
    - To insert a new song, press `i`
    - To remove an existing song, press `d`
    - To search the list by album/artist, press `s`
    - To display the default playlist, press `p`
    - To display the shuffled playlist, press `r`
    - To display the sorted playlist, press `a`
    - To quit, press `q`
3. **Microservice**:
    - Run the microservice separately:
    ```bash
    python microservice.py
    ```
## Requirements
- C++ compiler (e.g., g++) for compiling C++ files.
- Python for running the microservice.
- `songs.txt` file in the correct format (songTitle;artistName;durationMinutes;durationSeconds;albumName).
## Example Usage
Here's an example to help you get started:
1. Start the C++ application to manage your playlist.
2. Insert, remove, search, or display songs as per your requirement.
3. Run the Python microservice to enable shuffling and sorting.
## Notes
1. Ensure `songs.txt` contains properly formatted data.
2. The `order.txt` file is used for communication between the main program and the microservice. Do not modify it manually.
3. Any changes made to the playlist through insert or remove operations will be saved back to `songs.txt`.
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
