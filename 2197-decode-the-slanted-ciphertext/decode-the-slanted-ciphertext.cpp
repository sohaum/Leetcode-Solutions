class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n==0) return "";
        int cols = n / rows;
        string result = "";

        // Traverse diagonals starting from first row
        for (int j = 0; j < cols; j++) {
            int i = 0, col = j;
            while (i < rows && col < cols) {
                result.push_back(encodedText[i * cols + col]);
                i++;
                col++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};