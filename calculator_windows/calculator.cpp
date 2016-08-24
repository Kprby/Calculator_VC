#include "calculator.h"
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

/*返回运算符s的运算类型
若s是右结合单目运算符(如sin、左括号), 返回right_combination
若s是数, 返回no_type
若s是左结合单目运算符(如！、右括号), 返回left_combination
若s是双单目运算符(如+), 返回binocular*/
Calculator::ArithmeticType Calculator::getSymArithmeticType(Symbol s)
{
    switch (s)
    {
        case g_arcsin:
        case g_arccos:
        case g_arctan:
        case g_sin:
        case g_cos:
        case g_tan:
        case g_ln:
        case g_log:
        case g_positive:
        case g_negative:
        case g_sqrt:
        case g_lbracket:
            return right_combination;
        case g_num:
        case g_pi:
        case g_e:
        case g_Ans:
            return no_type;
        case g_factorial:
        case g_rbracket:
            return left_combination;
        case g_plus:
        case g_minus:
        case g_multiply:
        case g_divide:
        case g_mod:
        case g_power:
        case g_root:
            return binocular;
        default:
            break;
    }
    return no_type;
}

//返回运算符s的优先级(详见Symbol的定义。 数、括号、错误的优先级没有意义)
int Calculator::getOperatorLevel(Symbol s)
{
    switch (s)
    {
        case g_lbracket:
        case g_rbracket:
            return 6;
        case g_plus:
        case g_minus:
            return 5;
        case g_multiply:
        case g_divide:
        case g_mod:
            return 4;
        case g_arcsin:
        case g_arccos:
        case g_arctan:
        case g_sin:
        case g_cos:
        case g_tan:
        case g_ln:
        case g_log:
        case g_positive:
        case g_negative:
            return 3;
        case g_power:
        case g_root:
        case g_sqrt:
            return 2;
        case g_factorial:
            return 1;
        default:
            return 0;
    }
}

//输出式项i，用于调试
void Calculator::showItem(const Item &i)
{
    switch (i.sym)
    {
        case g_plus:
        case g_positive:
            cout << '+';
            break;
        case g_minus:
        case g_negative:
            cout << '-';
            break;
        case g_arcsin:
            cout << "arcsin";
            break;
        case g_arccos:
            cout << "arccos";
            break;
        case g_arctan:
            cout << "arctan";
            break;
        case g_sin:
            cout << "sin";
            break;
        case g_cos:
            cout << "cos";
            break;
        case g_tan:
            cout << "tan";
            break;
        case g_multiply:
            cout << '*';
            break;
        case g_divide:
            cout << '/';
            break;
        case g_mod:
            cout << "mod";
            break;
        case g_ln:
            cout << "ln";
            break;
        case g_log:
            cout << "log";
            break;
        case g_power:
            cout<<'^';break;
        case g_root:
            cout << "root";
            break;
        case g_sqrt:
            cout << "sqrt";
            break;
        case g_factorial:
            cout << '!';
            break;
        case g_lbracket:
            cout << '(';
            break;
        case g_rbracket:
            cout << ')';
            break;
        case g_num:
            cout << i.val;
            break;
        case g_pi:
            cout << "pi";
            break;
        case g_e:
            cout << "e";
            break;
        case g_Ans:
            cout << "Ans";
            break;
        case g_error:
            cerr << "showItemError:g_error\n";
            break;
        default:
            cerr << "showItemError\n";
            break;
    }
}

//输出后缀表达式postfix_exp，用于调试
void Calculator::showRPN(std::list<Item> &postfix_exp)
{
    for (const Item &i : postfix_exp)
    {
        showItem(i);
        cout << ' ';
    }
    cout << endl;
}

/*从字符串输入流sin中读取一个字母字符串,并查找该字母字符串代表的运算符或特殊的数
若查找成功，则返回相应的运算符或数的类型
否则返回g_error*/
Calculator::Symbol Calculator::getsym(istringstream &sin)
{
    string s;
    char c;

    //读取字母字符串，-1代表文件结束符
    while (sin.peek() !=-1 && isalpha(sin.peek()))
    {
        sin >> c;
        s.push_back(c);
    }

    //折半查找
    int i = 0, k, j = svec.size();
    while (i <= j)
    {
        k = ( i + j ) / 2;
        if (s < svec[k].str)
        {
            j = k - 1;
        }
        else if (s > svec[k].str)
        {
            i = k+ 1;
        }
        else if (s == svec[k].str)
        {
            return svec[k].sym;
        }
    }

    return g_error;
}

/*从字符串输入流sin中读取一个非字母的单字符所表示的运算符
g_front代表上一个式项的类型,用于区分加号和正号、减号和负号*/
Calculator::Symbol Calculator::getoperator(istringstream &sin, Symbol g_front)
{
    char c;
    sin >> c;
    ArithmeticType a;
    switch (c)
    {
        case '+':
            a = getSymArithmeticType(g_front);
            if (a == no_type || a == left_combination)
            {
                //若'+'左边的是数或左结合运算符，则代表是加号
                return g_plus;
            }
            else
            {
                //否则代表正号
                return g_positive;
            }
        case '-':
            a = getSymArithmeticType(g_front);
            if (a == no_type || a == left_combination)
            {
                //若'-'左边的是数或左结合运算符，则代表是减号
                return g_minus;
            }
            else
            {
                //否则代表负号
                return g_negative;
            }
        case '*':
            return g_multiply;
        case '/':
            return g_divide;
        case '%':
            return g_mod;
        case '^':
            return g_power;
        case '!':
            return g_factorial;
        case '(':
            return g_lbracket;
        case ')':
            return g_rbracket;
        default:
            return g_error;
            break;
    }
}

/*从字符串输入流sin中读取一个式项到item
g_front代表上一个式项的类型，用于检测表达式是否有格式错误
若读取成功且没有格式错误，则返回空字符串
否则返回含有出错信息的字符串*/
string Calculator::getItem(istringstream &sin, Item &item, Symbol g_front)
{
    char c = sin.peek();

    //跳过空格，-1代表文件结束符
    while (c !=-1 && isspace(c))
    {
        sin.get();
        c = sin.peek();
    }

    if (c != -1)
    {
        if (isdigit(c))
        {
            //从流中读取一个十进制数（可以以科学计数法表示）
            if (sin >> item.val) //判断输入的数值是否溢出，数值范围由double决定
            {
                item.sym = g_num;
            }
            else
            {
                return "overflow\n";
            }
        }
        else if (isalpha(c))
        {
            //从流中读取一个字母字符串并得到该字母字符串代表的类型
            item.sym = getsym(sin);
            //若g.sym代表一个特殊的数，则将对应的数值赋给g.val
            switch (item.sym)
            {
                case g_e:
                    item.val = e;
                    break;
                case g_pi:
                    item.val = pi;
                    break;
                case g_Ans:
                    item.val = Ans;
                    break;
                default:
                    break;
            }
        }
        else
        {
            //从流中读取一个非字母的单字符所表示的运算符
            item.sym = getoperator(sin, g_front);
        }
    }

    //若读取出错，返回语法错误信息
    if (item.sym == g_error)
    {
        return "Syntax ERROR\n";
    }
    else
    {
        return "";
    }
}

/*将中缀表达式infix_exp转换成后缀表达式postfix_exp
若转换成功，则返回空字符串
否则返回含有出错信息的字符串*/
string Calculator::changeintoRPN(string infix_exp, list<Item> &postfix_exp)
{
    postfix_exp.clear();
    stack<Symbol, list<Symbol>> sym_stack; //定义符号栈
    sym_stack.push(g_lbracket); //压入一个左括号到符号栈，作为表达式开始
    infix_exp.push_back(')'); //在中缀表达式infix_exp尾部添加右括号，作为表达式结束
    istringstream sin(infix_exp);   /*将中缀表达式infix_exp绑定到字符串输入流sin，
                                    用于便捷地读取中缀表达式infix_exp*/
    Symbol g_front = g_lbracket;   //记录上一个式项的类型，用于辅助检测错误
    Item item;    //用于储存当前读取的式项

    //通过读取字符串输入流sin来读取中缀表达式infix_exp，-1代表文件结束符
    while (sin.peek() != -1)
    {
        string exc; //用于储存异常信息

        //若读取流时发生异常则返回异常信息
        if ( (exc = getItem(sin, item, g_front)) != "")
        {
            return exc;
        }

        //判断是否有语法错误
        ArithmeticType front_arith = getSymArithmeticType(g_front); //记录上一个式项运算类型
        ArithmeticType current_arith = getSymArithmeticType(item.sym); //记录当前式项运算类型
        if
        (
            //右结合单目运算符的右边不能是左结合单目运算符或双目运算符
            (front_arith == right_combination
                && (current_arith == left_combination || current_arith == binocular))

            //数的右边不能是右结合单目运算符或数
            || (front_arith == no_type
                && (current_arith == right_combination || current_arith == no_type))

            //左结合单目运算符右边不能是右结合单目运算符或数
            || (front_arith == left_combination
                && (current_arith == right_combination || current_arith == no_type))

            //双目运算符右边不能是左结合单目运算符或双目运算符
            || (front_arith == binocular
                && (current_arith == left_combination || current_arith == binocular))
        )
        {
            return "Syntax ERROR\n";
        }

        //处理读取到的式项item
        if (current_arith == no_type)
        {
            //若式项item代表一个数，则直接输出到后缀表达式postfix_exp中
            postfix_exp.emplace_back(item);
            g_front = item.sym;
        }
        else if (current_arith == right_combination)
        {
            //若式项item代表右结合单目运算符，则直接输出到后缀表达式postfix_exp中
            sym_stack.push(item.sym);
            g_front = item.sym;
        }
        else if (item.sym == g_rbracket)
        {
            /*若式项item代表右括号，则不断将符号栈中的符号弹出并输入后缀表达式postfix_exp
            直到匹配到左括号或符号栈为空*/
            while (sym_stack.top() != g_lbracket && ! sym_stack.empty())
            {
                postfix_exp.emplace_back(sym_stack.top());
                sym_stack.pop();
            }

            if (sym_stack.empty())
            {
                //若没有匹配到左括号，则返回“丢失左括号”
                return "lose left bracket\n";
            }
            else
            {
                //否则弹出左括号
                sym_stack.pop();
                g_front = item.sym;
            }
        }
        else
        {
            //处理非括号、非右结合的运算符

            /*循环条件：符号栈顶部运算符的优先级不小于当前运算符item.sym,
            循环体：符号栈顶部运算符弹出并输入后缀表达式postfix_exp*/
            while (getOperatorLevel(item.sym) >= getOperatorLevel(sym_stack.top()))
            {
                postfix_exp.emplace_back(sym_stack.top());
                sym_stack.pop();
            }

            sym_stack.push(item.sym);   //将当前运算符压人符号栈
            g_front = item.sym;
        }
    }//中缀表达式infix_exp读取结束

    /*若中缀表达式infix_exp没有语法错误，
    则符号栈应为空*/
    if (sym_stack.empty())
    {
        return "";
    }
    else
    {
        //符号栈中有左括号剩下
        return "lose right bracket\n";
    }
}

/*执行运算，操作数在运算栈Computing_stack中，运算符由s表示，
运算结果压人运算栈Computing_stack
若没有算术错误，则返回true
否则返回false*/
bool Calculator::calculate_term(stack<double,list<double>> &Computing_stack, Symbol s)
{
    double o1, o2;
    if (getSymArithmeticType(s) == binocular)
    {
        o2 = Computing_stack.top();
        Computing_stack.pop();
        o1 = Computing_stack.top();
        Computing_stack.pop();
    }
    else
    {
        o1 = Computing_stack.top();
        Computing_stack.pop();
    }
    switch (s)
    {
        case g_plus:
            {
                Computing_stack.push(o1 + o2);
                return true;
            }
        case g_minus:
            {
                Computing_stack.push(o1 - o2);
                return true;
            }
        case g_arcsin:
            return garcsin(o1, o2, Computing_stack);
        case g_arccos:
            return garccos(o1, o2, Computing_stack);
        case g_arctan:
            return garctan(o1, o2, Computing_stack);
        case g_sin:
            return gsin(o1, o2, Computing_stack);
        case g_cos:
            return gcos(o1, o2, Computing_stack);
        case g_tan:
            return gtan(o1, o2, Computing_stack);
        case g_multiply:
            {
                Computing_stack.push(o1*o2);
                return true;
            }
        case g_divide:
            if (o2 != 0.0)
            {
                Computing_stack.push(o1 / o2);
                return true;
            }
            else
            {
                return false;
            }
        case g_mod:
            if (o2 != 0.0)
            {
                Computing_stack.push(fmod(o1, o2));
                return true;
            }
            else
            {
                return false;
            }
        case g_ln:
            if (o1 > 0.0)
            {
                Computing_stack.push(log(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_log:
            if (o1 > 0.0)
            {
                Computing_stack.push(log10(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_positive:
            {
                Computing_stack.push(o1);
                return true;
            }
        case g_negative:
            {
                Computing_stack.push(-1 * o1);
                return true;
            }
        case g_power:
            return gpower(o1, o2, Computing_stack);
        case g_root:
            return groot(o1, o2, Computing_stack);
        case g_sqrt:
            if (o1 >= 0)
            {
                Computing_stack.push(sqrt(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_factorial:
            return gfactorial(o1, o2, Computing_stack);
        default: return false;
    }
    return true;
}

bool Calculator::garcsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    if (o1 >= -1.0 && o1 <= 1.0)
    {
        double d = asin(o1);
        if (a == degree)
        {
            d = DegreeToRadian(d);
        }
        else if (a == gradient)
        {
            d = GradientToRadian(d);
        }
        Computing_stack.push(d);
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::garccos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    if ( o1 >= -1.0 && o1 <= 1.0)
    {
        double d = acos(o1);
        if (a == degree)
        {
            d = DegreeToRadian(d);
        }
        else if (a == gradient)
        {
            d = GradientToRadian(d);
        }
        Computing_stack.push(d);
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::garctan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = atan(o1);
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(d);
    return true;
}

bool Calculator::gsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(sin(d));
    return true;
}

bool Calculator::gcos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(cos(d));
    return true;
}

bool Calculator::gtan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }

    if (fabs(fmod(d, pi)) != pi / 2)
    {
        Computing_stack.push(tan(d));
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::gpower(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    if ((o1 == 0 && o2 <= 0) || (o1 < 0 && modf(o2, &d) == 0.0))
    {
        return false;
    }
    else
    {
        Computing_stack.push(pow(o1, o2));
        return true;
    }
}

bool Calculator::groot(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    o1 = 1.0 / o1;
    if ((o2 == 0 && o1 <= 0) || (o2 < 0 && modf(o1, &d) != 0.0))
    {
        return false;
    }
    else
    {
        Computing_stack.push(pow(o2, o1));
        return true;
    }
}

bool Calculator::gfactorial(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    if (modf(o1, &d) == 0.0 && o1 >= 0)
    {
        int sum = 1;
        for(int i = 2; i <= o1; ++i)
        {
            sum *= i;
            if (sum <= 0)
            {
                return false;
            }
        }
        Computing_stack.push(sum);
        return true;
    }
    else
    {
        return false;
    }
}

/*对中缀表达式infix_exp求值
若成功，则返回以字符串表示的求值结果
否则返回以字符串表示的出错信息*/
string Calculator::calculate_exp(string infix_exp)
{
    list<Item> postfix_exp;
    string cs(changeintoRPN(infix_exp, postfix_exp));
    //showRPN(postfix_exp);

    if (!(cs == ""))
    {
        //若中缀表达式转换后缀表达式失败，则返回出错信息
        return cs;
    }

    stack<double, list<double>> Computing_stack;
    for (const Item &item : postfix_exp)
    {
        if (getSymArithmeticType(item.sym) == no_type)
        {
            Computing_stack.push(item.val);
        }
        else
        {
            if (calculate_term(Computing_stack, item.sym) == false)
            {
                return "Math ERROR\n";
            }
        }
    }
    Ans = Computing_stack.top();
    ostringstream sout;
    sout << setprecision(significant_figures) << Ans;
    return sout.str();
}
