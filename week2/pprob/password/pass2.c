






        if (x >= 97 && x <= 122)
        {
            bool lower = true;
            printf("lower = %d\n", lower);
        }
        else if (x >= 65 && x <= 90)
        {
            bool upper = true;
            printf("upper = %d\n", upper);
        }

        else if (x >= 48 && x <= 57)
        {
            bool number = true;
            printf("number = %d\n", number);
        }
        else if ((x >= 33 && x < +47) || (x >= 58 && x <= 64) || (x >= 91 && x <= 96) || (x >= 123 && x <= 126))
        {
            bool symbol = true;
            printf("symbol = %d\n", symbol);
        }
    }
//        return true;
//        return false;
//}
        bool lower, upper, number, symbol;
        if ((lower = true) && (upper = true) && (number = true) && (symbol = true))
//        {
//          printf("\n");
            return true;
//        }
        else
//        {
            return false;
    printf("\n");

}

