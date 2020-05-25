//
// Created by user on 08/05/2020.
//
#include "utils.h"

void trim(string &str)
{
    const string WHITE_SPACE = " \t\n\v\f\r";
    str.erase(0, str.find_first_not_of(WHITE_SPACE));
    str.erase(str.find_last_not_of(WHITE_SPACE) + 1, string::npos);
}

vector<string> decompose(string s, char sep) {
    vector<string> elements;
    string usage = "";
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == sep) {
            trim(usage);
            elements.push_back(usage);
            usage = "";
        }
        else {
            usage += s[i];

            if (i == s.length() - 1) {
                trim(usage);
                elements.push_back(usage);
            }

        }
    }
    return elements;
}

bool compare_str(string str1, string str2) {
    trim(str1);
    trim(str2);
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    if (str1 == str2) return true;
    return false;
}


vector<string> split(string str, char delimiter, size_t max_splits)
{
    str += '\n';
    string temp;
    vector<string> result;
    stringstream line_stream(str);


    for (size_t i = 0; i < max_splits; i++)
    {
        getline(line_stream, temp, delimiter);
        trim(temp);
        result.push_back(temp);
    }

    getline(line_stream, temp, '\n');
    trim(temp);
    result.push_back(temp);

    return result;
}

vector<int> getNodeValues(string text_line)
{
    vector<string> tmp = split(text_line, ',', 3);
    vector<int> result;
    int size1 = tmp[0].size() - 1;
    result.push_back(stoi(tmp[0].substr(1, size1)));
    result.push_back((int)stof(tmp[1]));
    int size2 = tmp[2].size() - 1;
    result.push_back((int)stof(tmp[2].substr(0,size2 )));
    return result;

}

vector<int> getEdgeValues(string text_line)
{
    vector<string> tmp = split(text_line, ',', 2);
    vector<int> result;
    result.push_back(stoi(tmp[0].substr(1, string::npos)));
    int size = tmp[1].size()-1;
    result.push_back(stoi(tmp[1].substr(0, size)));
    return result;
}



bool in(vector<int> vec, int n)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == n)
            return true;
    }
    return false;
}