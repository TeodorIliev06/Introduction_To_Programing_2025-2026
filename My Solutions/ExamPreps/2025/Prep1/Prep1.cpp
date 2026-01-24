#include <iostream>

const int MAX_SIZE = 100;

void readArr(int* src, size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> src[i];
    }
}

int findMaxMin(const int* src, size_t size, int&minVal, int& maxVal) {
    int sum = 0, avg = 0;
    minVal = src[0];
    maxVal = src[0];

    for (size_t i = 0; i < size; i++)
    {
        if (src[i] < minVal)
        {
            minVal = src[i];
        }
        else if (src[i] > maxVal)
        {
            maxVal = src[i];
        }

        sum += src[i];
    }

    avg = sum / size;

    int closestToAvgInd = 0, minDiff = maxVal;
    for (size_t i = 0; i < size; i++)
    {
        int currDiff = std::abs(src[i] - avg);
        if (currDiff < minDiff)
        {
            minDiff = currDiff;
            closestToAvgInd = i;
        }
    }

    return src[closestToAvgInd];
}

bool isPalindromeExcluding(const char* src, size_t skip1, size_t skip2) {
    int left = 0;
    int right = strlen(src) - 1;

    while (left < right) {
        if (left == skip1 || left == skip2) 
        { 
            left++;
            continue;
        }

        if (right == skip1 || right == skip2) 
        {
            right--;
            continue;
        }

        if (src[left] != src[right]) 
            return false;

        left++;
        right--;
    }
    return true;
}

bool checkStr(const char* src) {
    size_t len = strlen(src);

    if (len < 2)
    {
        return false;
    }

    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = i + 1; j < len; j++)
        {
            if (isPalindromeExcluding(src, i, j))
            {
                return true;
            }
        }
    }

    return false;
}

int charToNum(char ch) {
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 10;
    }

    return -1;
}

int convert(const char* src, int k) {
    int result = 0;

    int len = strlen(src);
    for (size_t i = 0; i < len; i++)
    {
        int currValue = charToNum(src[i]);
        if (currValue >= k || currValue == -1)
        {
            return 0;
        }

        result = (result * k) + currValue;
    }

    return result;
}

int main()
{
    // 1
    //int src[MAX_SIZE];
    //int minVal, maxVal;
    //size_t size;

    //std::cout << "Please enter valid array size: ";
    //std::cin >> size;
    //std::cout << std:: endl;

    //readArr(src, size);
    //std::cout << findMaxMin(src, size, minVal, maxVal) << std::endl;
    //std::cout << "max:" << maxVal << " " << "min:" << minVal << std::endl;

    // 2
    //int n;
    //std::cin >> n;
    //std::cin.ignore();

    //char* input = new char [n+1];
    //std::cin.getline(input, n+1, '\n');
    //std::cout << std::boolalpha << checkStr(input) << std::endl;

    // 3
    int n, k;
    std::cout << "Please enter a base (2-36)\n";
    std::cin >> k;

    std::cout << "Please enter how many digits you will use\n";
    std::cin >> n;
    std::cin.ignore();

    char* input = new char[n + 1];
    std::cin.getline(input, n + 1, '\n');

    std::cout << convert(input, k) << std::endl;
    delete[] input;
}