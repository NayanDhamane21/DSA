class Solution {
public:
    void removere(string&s,string&part)
    {
        int found=s.find(part);
        if(found!=string::npos)
        {
            string left_part = s.substr(0,found);
            string right_part=s.substr(found+part.size(),s.size());
            s=left_part + right_part;

            removere(s,part);
        }
        else{
            return;
        }

    }
    string removeOccurrences(string s, string part) {
        removere(s,part);
        return s;
        
    }
};