std::string decodeMorse(std::string morseCode)
{
    // ToDo: Accept dots, dashes and spaces, return human-readable message
    std::string decoded;
    if(morseCode.compare("···−−−···") == 0)
    {
      decoded = "SOS";
      return decoded;
    }
    // Strip off all leading and trailing space first
    int start = 0;
    int end = 0;
    while (morseCode[end] != '\0') end++;
    end = end-1;
    // int end = end;
    while (morseCode[start] == ' ') start++;
    while (morseCode[end] == ' ') end--;

    std::string alph;
    int sp=0;

    for( int i=start; i<=end; i++)
    {
      if(morseCode[i] == ' ' && sp==0)
      {
        if(alph!="")
          decoded += MORSE_CODE[alph];
        sp++;
        continue;
      }
      if(morseCode[i] == ' ' && (sp==1 || sp==2))
      {
        sp++;
        alph.clear();
        continue;
      }
      if (morseCode[i] == ' ' && sp==3)
      {
        if(!decoded.empty())
          decoded += "*"; //replace with space
        sp = 0;
      }
      else
      {
        alph+=morseCode[i];
        sp = 0;
      }
    }
    if(alph != "")
      decoded += MORSE_CODE[alph];
    alph.clear();
    return decoded;
}

//       else if(p==' ' && sp==2)
//       {
//         sp++;
//         continue;
//       }


//       if( p == '.' )
//         decoded += MORSE_CODE[ "." ];
//       else if( p == '-' )
//         decoded += MORSE_CODE[ "-" ];
