#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class SentimentAnalyzer {
public:
    // Loading positive words from the uploaded file i.e positive words.txt
    void loadPositiveWords(const string& filename) {
        loadWords(filename, positiveWords_, 1); // Set the value for positive words as +1
    }

    // Loading negative words from the uploaded file i.e negative words.txt
    void loadNegativeWords(const string& filename) {
        loadWords(filename, negativeWords_, -1); // Set the value for negative words as -1
    }

    // In the below code snippet, we analyze the sentiment of user input.
    int analyzeSentiment(const string& userInput) const {
        // Extract words from user input
        unordered_map<string, int> wordScores = extractWordsWithScores(userInput);

        // Count positive and negative words
        int positiveCount = countMatchingWords(wordScores, positiveWords_);
        int negativeCount = countMatchingWords(wordScores, negativeWords_);

        // Check for negation and adjust sentiment
        if (containsNegation(wordScores, userInput)) {
            swap(positiveCount, negativeCount);
        }

        // Adjust sentiment score based on overall counts
        int totalScore = positiveCount - negativeCount;

        return totalScore;
    }

private:
    // Maps to store positive and negative words with their scores
    unordered_map<string, int> positiveWords_;
    unordered_map<string, int> negativeWords_;
    unordered_set<string> negationWords = {"not", "no", "never", "nor", "neither", "nothing"};

    // Load words from a file into a specified unordered_map with scores
    void loadWords(const string& filename, unordered_map<string, int>& wordMap, int score) const {
        ifstream file(filename);
        if (file.is_open()) {
            string word;
            while (file >> word) {
                // Convert to lowercase before inserting
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                wordMap[word] = score;
            }
            file.close();
        } else {
            // Print an error message if the file is not opening.
            cerr << "Error opening file: " << filename << endl;
        }
    }

    // Extract words from a text with their scores, removing punctuation and converting to lowercase
    unordered_map<string, int> extractWordsWithScores(const string& text) const {
        unordered_map<string, int> wordScores;
        istringstream iss(text);
        string word;

        while (iss >> word) {
            // Remove punctuations 
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

            // Convert to lowercase before inserting
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            // Check for negation and adjust the score
            int score = 1; // Default score for non-negated words
            if (containsNegation(wordScores, word)) {
                score = -score; // Negate the score if the word is in a negation context
            }

            wordScores[word] = score;
        }

        return wordScores;
    }

    // Check if the given word is in a negation context
    bool containsNegation(const unordered_map<string, int>& wordScores, const string& userInput) const {
        // Check if the user input contains any negation words
        for (const auto& negationWord : negationWords) {
            if (userInput.find(negationWord) != string::npos) {
                return true;
            }
        }
        return false;
    }

    // Count the number of words in a set that match the words in another set
    int countMatchingWords(const unordered_map<string, int>& wordScores, const unordered_map<string, int>& lexicon) const {
        int count = 0;
        for (const auto& pair : wordScores) {
            if (lexicon.count(pair.first)) {
                count += pair.second;
            }
        }
        return count;
    }
};

int main() {
    SentimentAnalyzer analyzer;

    // Loading positive and negative words from the uploaded files
    analyzer.loadPositiveWords("positive words.txt");
    analyzer.loadNegativeWords("negative words.txt");

    // Take user input as a paragraph
    cout << "Enter text for sentiment analysis (press Ctrl+D to end input): ";
    stringstream inputParagraphStream;
    string line;
    while (getline(cin, line)) {
        inputParagraphStream << line << endl;
    }
    string userInput = inputParagraphStream.str();

    // Analyzing sentiment
    int sentimentScore = analyzer.analyzeSentiment(userInput);

    // Determine sentiment label
    string sentimentLabel;
    if (sentimentScore > 0) {
        sentimentLabel = "Positive";
    } else if (sentimentScore < 0) {
        sentimentLabel = "Negative";
    } else {
        sentimentLabel = "Neutral";
    }

    // Output/result
    cout << "\n Sentiment Score: " << sentimentScore << endl;
    cout << "Sentiment Label: " << sentimentLabel << endl;

    return 0;
}




