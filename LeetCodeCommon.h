#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

//////////// UTILITIES ////////////////
void trimLeftTrailingSpaces (std::string &input);

void trimRightTrailingSpaces (std::string &input);

int stringToInteger(std::string input);

/////////////// STRUCTS ////////////////
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x);
};

//////////// CONVERSION ////////////////
std::vector<int> stringToIntegerVector(std::string input);

std::string integerVectorToString(std::vector<int> list, int length = -1);

ListNode* stringToListNode(std::string input);

std::string listNodeToString(ListNode* node);

std::string stringToString(std::string input);