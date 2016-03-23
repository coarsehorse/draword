#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

char A[] = "   #     # #   #   # ########     ##     ##     #";
char B[] = "####   #   #  #   #  # #### #     ##     ########";
char C[] = "  ####  #    ##      #      #       #    #  #### ";
char D[] = "####   #   #  #    # #     ##     ##     ########";
char E[] = "########      #      #####  #      #      #######";
char F[] = "########      #      #####  #      #      #      ";
char G[] = "  ####  #    ##      #      #   ### #    #  ### #";
char H[] = "#     ##     ##     #########     ##     ##     #";
char I[] = "   #             #      #      #      #      #   ";
char J[] = "     #      #      #      #      #  #   #   ###  ";
char K[] = "#     ##   #  ####   #  #   #   #  #    # #     #";
char L[] = "#      #      #      #      #      #     ########";
char M[] = "##   ### # # ##  #  ##  #  ##     ##     ##     #";
char N[] = "##    ###    ## #   ##  #  ##   # ##    ###    ##";
char O[] = "   #     ###   #   # #     # #   #   ###     #   ";
char P[] = "###### #     ##     ##    # #####  #      #      ";
char Q[] = "   #     ###   #   # #     # #  ##   ####    #  #";
char R[] = "###### #     ##     ##   ## ####   #   #  #    ##";
char S[] = "  ###   #   ####      ###       #####   #   ###  ";
char T[] = "########  #  #   #      #      #      #      #   ";
char U[] = "#     ##     ##     ##     ##     ##     # ##### ";
char V[] = "#     ##     ##     ##     # #   #   # #     #   ";
char W[] = "#     ##     ##     ##  #  ##  #  # # # #   # #  ";
char X[] = "#     # #   #   # #     #     # #   #   # #     #";
char Y[] = "#     ##     # #   #   ###     #      #      #   ";
char Z[] = "#######     ##    #     #     #    ##     #######";

char d1[] = "   #     ##    # #      #      #      #    ##### ";
char d2[] = " ##### #     #     #   ###   #     #      #######";
char d3[] = " ##### #     #      # #####       ##     # ##### ";
char d4[] = "   #  #   #  #  #   # #    # ######      #      #";
char d5[] = "########      #      ######       #      ####### ";
char d6[] = "  ##### #     #      # #######    ##     # ##### ";
char d7[] = "#######      #     #     #     #     #      #    ";
char d8[] = " ##### #     ##     # ##### #     ##     # ##### ";
char d9[] = " ####  #    ###    ## #### #      #     # #####  ";
char d0[] = "  ###   #   # # #   ##  #  ##   # # #   #   ###  ";

char SPACE[] = "                                                 ";
char exclMark[] = "  ###    ###    ###    ###     #             #   ";
char NotSupp[] = "#########   ### # # ##  #  ## # # ###   #########";

class DrString
{
	vector<char> r[7];
	char draw_s;
public:

	DrString(char *a_in_arr)
	{
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				r[i].push_back(a_in_arr[i * 7 + j]);
	}

	DrString(char s)
	{
		draw_s = s;
	}

	void output()
	{
		vector<char>::iterator start, finish, iter;

		for (int i = 0; i < 7; i++) {
			start = r[i].begin();
			finish = r[i].end();
			for (iter = start; iter != finish; iter++)
				cout << (*iter == '#' ? draw_s : *iter);
			cout << "\n";
		}
	}

	void operator +=(DrString *right)
	{
		char little_space[2];

		little_space[0] = ' ';
		little_space[1] = ' ';

		for (int i = 0; i < 7; i++) {
			r[i].insert(r[i].end(), right->r[i].begin(), right->r[i].end());
			r[i].insert(r[i].end(), little_space, little_space + 2);
		}
	}
};

char *pointOnAlpha(char alpha)
{
	switch(alpha)
	{
		case 'a':
			return A;
		case 'b':
			return B;
		case 'c':
			return C;
		case 'd':
			return D;
		case 'e':
			return E;
		case 'f':
			return F;
		case 'g':
			return G;
		case 'h':
			return H;
		case 'i':
			return I;
		case 'j':
			return J;
		case 'k':
			return K;
		case 'l':
			return L;
		case 'm':
			return M;
		case 'n':
			return N;
		case 'o':
			return O;
		case 'p':
			return P;
		case 'q':
			return Q;
		case 'r':
			return R;
		case 's':
			return S;
		case 't':
			return T;
		case 'u':
			return U;
		case 'v':
			return V;
		case 'w':
			return W;
		case 'x':
			return X;
		case 'y':
			return Y;
		case 'z':
			return Z;

		case '1':
            return d1;
		case '2':
			return d2;
        case '3':
            return d3;
		case '4':
			return d4;
        case '5':
            return d5;
        case '6':
            return d6;
        case '7':
            return d7;
        case '8':
            return d8;
        case '9':
            return d9;
        case '0':
            return d0;

        case ' ':
            return SPACE;
		case '!':
			return exclMark;

        default:
			return NotSupp;
	}
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "<< Using: draword \"[text_to_output]\" [placeholder]\n";
        return 1;
    }

    DrString str_to_draw(argv[2][0]);
	char *argv_p = argv[1];

	while (*argv_p != '\0')
		str_to_draw += new DrString(pointOnAlpha((char)tolower(*argv_p++)));

	str_to_draw.output();

	return 0;
}
