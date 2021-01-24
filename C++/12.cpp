class Solution {
public:
    string intToRoman(int num) {
        string result;
        int quotient = 0;
        int remainder = 0;
        while (true)
        {
            quotient = num / 1000;
            result += string(quotient, 'M');
            num = num % 1000;
            quotient = num / 100;
            if (quotient == 9)
            {
                result += "CM";
            }
            if (quotient == 4)
            {
                result += "CD";
            }
            if (quotient < 4)
            {
                result += string(quotient, 'C');
            }
            if (quotient >= 5 && quotient < 9)
            {
                result += "D";
                result += string(quotient - 5, 'C');
            }
            num = num % 100;
            quotient = num / 10;
            if (quotient == 9)
            {
                result += "XC";
            }
            if (quotient == 4)
            {
                result += "XL";
            }
            if (quotient < 4)
            {
                result += string(quotient, 'X');
            }
            if (quotient >= 5 && quotient < 9)
            {
                result += "L";
                result += string(quotient - 5, 'X');
            }
            num = num % 10;
            if (num == 9)
            {
                result += "IX";
            }
            if (num == 4)
            {
                result += "IV";
            }
            if (num < 4)
            {
                 result += string(num, 'I');
            }
            if (num >= 5 && num < 9)
            {
                result += "V";
                result += string(num - 5, 'I');
            }
            break;

        }
        return result;
    }
};