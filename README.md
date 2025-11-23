# 📊 Data Structure Visualizer

A comprehensive web-based visualizer for learning and practicing data structures operations. Built with C++ (Crow framework) backend and modern HTML/CSS/JavaScript frontend.

## 🌟 Features

### 1️⃣ Arrays
- **Traversal** - View all elements
- **Insertion** - Insert at any position
- **Deletion** - Delete by position or value
- **Searching** - Linear Search & Binary Search
- **Update** - Modify values at specific positions

### 2️⃣ Linked Lists
Includes all variants:
- **Singly Linked List**
- **Doubly Linked List**
- **Circular Linked List**

Operations:
- Insert at beginning/end/position
- Delete node (beginning/end/position/value)
- Search for values
- Reverse linked list
- Update values

### 3️⃣ Stacks
- **Stack using Array**
- **Stack using Linked List**

Operations:
- Push / Pop / Peek
- Applications:
  - Parenthesis checker
  - Reverse string

### 4️⃣ Queues
Includes variants:
- **Normal Queue**
- **Circular Queue**
- **Double-Ended Queue (Deque)**
- **Priority Queue**

Operations:
- Enqueue / Dequeue
- Front / Rear access

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler** (GCC/G++ or MinGW on Windows)
- **Windows OS** (for the provided build scripts)
- **Web Browser** (Chrome, Firefox, Edge, etc.)

### Installation

1. **Clone or Download this repository**
   ```bash
   git clone https://github.com/YOUR_USERNAME/data-structure-visualizer.git
   cd data-structure-visualizer
   ```
   
   Or download as ZIP from GitHub and extract it.

2. **Build the Project**
   
   On Windows, simply run:
   ```bash
   build.bat
   ```
   
   This will compile the C++ code and create `dsa_visualizer.exe`

3. **Run the Server**
   ```bash
   run.bat
   ```
   
   Or directly:
   ```bash
   dsa_visualizer.exe
   ```

4. **Open in Browser**
   
   Navigate to: `http://localhost:18080`

## 📖 How to Use

1. **Select Data Structure**: Click on Arrays, Linked Lists, Stacks, or Queues
2. **Select Type** (if applicable): Choose the specific variant
3. **Perform Operations**: Use the provided inputs and buttons to perform operations
4. **Visualize**: Click "Display Data Structure" to see the current state

## 🏗️ Project Structure

```
PROJECT/
├── src/
│   ├── main.cpp              # Main server file with API routes
│   ├── linked_list.h         # Linked list class definitions
│   ├── linked_list.cpp       # Linked list implementations
│   ├── data_structures.h      # Array, Stack, Queue definitions
│   └── data_structures.cpp   # Array, Stack, Queue implementations
├── public/
│   └── index.html            # Frontend web interface
├── external/
│   ├── Crow/                 # Crow web framework
│   └── asio/                 # Asio networking library
├── build.bat                 # Build script for Windows
├── run.bat                   # Run script
└── README.md                 # This file
```

## 🔧 Building from Source

### Windows (MinGW)

```bash
g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 \
    -I./external/Crow/include \
    -I./external/asio/include \
    -o dsa_visualizer.exe \
    -lws2_32 -lmswsock -pthread \
    -DASIO_STANDALONE
```

### Linux/Mac

```bash
g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 \
    -I./external/Crow/include \
    -I./external/asio/include \
    -o dsa_visualizer \
    -pthread \
    -DASIO_STANDALONE
```

## 🌐 API Documentation

See [API_DOCUMENTATION.md](API_DOCUMENTATION.md) for complete API reference.

## 📤 Uploading to GitHub

Want to share your code on GitHub? See [GITHUB_SETUP.md](GITHUB_SETUP.md) for step-by-step instructions.

## 🌍 Hosting Online

Want to host this online so others can access it via a web link? See [HOSTING.md](HOSTING.md) for hosting options and instructions.

## 📝 Example Usage

### Arrays
1. Select "Arrays"
2. Insert values: Enter value and position, click "Insert"
3. Search: Enter value, click "Linear Search" or "Binary Search"
4. Display: Click "Display Data Structure"

### Linked Lists
1. Select "Linked Lists" → Choose type (Singly/Doubly/Circular)
2. Insert: Enter value, click "Insert at Beginning" or "Insert at End"
3. Reverse: Click "Reverse" to reverse the entire list
4. Display: Visualize the linked list with arrows

### Stacks
1. Select "Stacks" → Choose "Stack (Array)" or "Stack (Linked List)"
2. Push: Enter value, click "Push"
3. Applications: Try "Check Parentheses" with expressions like `(a+b)*c`
4. Display: See stack from top to bottom

### Queues
1. Select "Queues" → Choose type
2. Enqueue: Add elements to the queue
3. Dequeue: Remove elements
4. Display: See queue from front to rear

## 🐛 Troubleshooting

### Server won't start
- Check if port 18080 is already in use
- Make sure `dsa_visualizer.exe` exists (run `build.bat` first)
- Check Windows Firewall settings

### Build errors
- Ensure you have MinGW or compatible C++ compiler installed
- Check that all files in `external/` directory are present
- Verify C++17 support in your compiler

### Browser shows connection error
- Make sure the server is running (`dsa_visualizer.exe`)
- Check the server console for error messages
- Try accessing `http://localhost:18080` directly

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License

This project is open source and available for educational purposes.

## 👨‍💻 Author

Created for educational purposes - Data Structures and Algorithms visualization.

## 🙏 Acknowledgments

- **Crow** - C++ micro web framework
- **Asio** - Cross-platform C++ library for network programming

---

**Note**: This application runs locally on your machine. For online hosting, you'll need a server that supports C++ applications (like a VPS, AWS EC2, or similar).

