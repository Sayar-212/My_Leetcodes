int romanToInt(char * s)
{
    int total = 0;
    int values[89]; //Only need space till max ASCII value (X = 88). 
    
    //Store corresponding values in array where index is the character itself. 
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100; 
    values['D'] = 500;
    values['M'] = 1000; 
    
    //Iterate over string. 
    for (int i = 0; i < strlen(s); ++i)
    {
        //Store curr. character and numeric value. 
        char c = s[i]; 
        int curr = values[c]; 
        
        //Only if the next character's value is greater does "subtraction" apply. 
        if ((c == 'X' || c == 'I' || c == 'C') && s[i + 1] != '\0' && curr < values[s[i + 1]])
        {
            total += values[s[i + 1]] - curr;
            ++i;
            continue;
        }
        //Otherwise, it's just adding the value of current character. 
        else total += curr; 
    }
    return total; 
}