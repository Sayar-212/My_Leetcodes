const char* doubleDigitMap[] = {
    " ",
    " ",
    "Twenty ",
    "Thirty ",
    "Forty ",
    "Fifty ",
    "Sixty ",
    "Seventy ",
    "Eighty ",
    "Ninety "
};

const char* tenMap[] = {
    "Ten ",
    "Eleven ",
    "Twelve ",
    "Thirteen ",
    "Fourteen ",
    "Fifteen ",
    "Sixteen ",
    "Seventeen ",
    "Eighteen ",
    "Nineteen ",
};

const char* digitmap[] = {
    " ",
    "One ",
    "Two ",
    "Three ",
    "Four ",
    "Five ",
    "Six ",
    "Seven ",
    "Eight ",
    "Nine ",
};


// Helper function to trim whitspaces at the end if exists.
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

// A generic function that appends three digits value to the output string
void appendThree(int* numarr, char* output, char* digitName){
    int toprint = 0;

    if(numarr[0]){
        strcat(output, digitmap[numarr[0]]);
        strcat(output, "Hundred ");
        toprint = 1;
    }

    if(numarr[1] > 1){
        strcat(output, doubleDigitMap[numarr[1]]);
        if(numarr[2]){
            strcat(output, digitmap[numarr[2]]);
        }
        toprint = 1;
    }
    else if(numarr[1] == 1){
        strcat(output, tenMap[numarr[2]]);
        toprint = 1;
    }
    else if(numarr[2]){
        strcat(output, digitmap[numarr[2]]);
        toprint = 1;
    }

    if(toprint){
        strcat(output, digitName);
    }
}



char* numberToWords(int num) {
    int numarr[12];

    char* output = malloc(sizeof(char)*500);
    strcpy(output, "");

    if(!num){
        strcat(output, "Zero");
        return output;
    }


    for(int i = 11; i >= 0; i--){
        if(num){
            numarr[i] = num % 10;
        }
        else{
            numarr[i] = 0;
        }
        num /= 10;
    }

    appendThree(&numarr[0], output, "Billion ");
    appendThree(&numarr[3], output, "Million ");
    appendThree(&numarr[6], output, "Thousand ");
    appendThree(&numarr[9], output, "");
    

    output = trimwhitespace(output);

    return output;
}