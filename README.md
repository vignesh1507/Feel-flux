# Feel-flux

Feel-flux is a **Sentiment Analysis** program written in **C++**. It reads positive, negative & neutral words from provided files and analyzes the sentiment of user input text, determining if the sentiment is **positive**, **negative**, or **neutral**. 
  
## Features 
- **Sentiment Analysis** is based on positive, negative, and neutral word lists.
- Detects **negation words** to flip sentiment where appropriate.
- Provides a **sentiment score** and **sentiment label** (Positive, Negative or Neutral). 

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/vignesh1507/Feel-flux.git
   ```

3. **Install a C++ compiler:**
   Ensure you have a C++ compiler installed. You can use:
   - **g++** for Linux/Windows (mingw)
   - **clang** for macOS/Linux
   - **MSVC** for Windows/macOS

4. **Create or add positive and negative word files:**
   The program requires text files containing positive and negative, neutral, and stop words.

   - `positive words.txt`
   - `negative words.txt`
   - `neutral words.txt`
   - `stop_list.txt`

## Compilation

To compile the program, use the following commands:

- **g++** (Linux/Windows):
  ```bash
  g++ -o Feel-flux main.cpp
  ```

- **clang** (macOS/Linux):
  ```bash
  clang++ -o Feel-flux main.cpp
  ```

- **MSVC** (Windows):
  ```bash
  cl main.cpp
  ```

## Usage

Once compiled, you can run the program from the command line:

```bash
./Feel-flux
```

### Input

The program prompts you to input a paragraph or sentence for sentiment analysis:

```bash
Enter text for sentiment analysis (press Ctrl+D to end input):
```

Type in the text you want to analyze and press **Enter**.

### Output

The program will output the **sentiment score** and **sentiment label** (Positive, Negative, Neutral):

```bash
Sentiment Score: 3
Sentiment Label: Positive
```

## File Structure

```
.
├── main.cpp         # Main C++ source code
├── positive words.txt    # File containing positive words
├── negative words.txt    # File containing negative words
├── neutral words.txt     # File containing neutral words
├── stop_list.txt         # File containing stop words
└── README.md             # Project README file
```

