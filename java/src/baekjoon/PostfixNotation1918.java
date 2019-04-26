package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class PostfixNotation1918 {
    private String mInfix;
    private HashMap<Character, Integer> operPriority;

    public PostfixNotation1918() {
        init();
        System.out.println(infixToPostfix());
    }

    public void init() {
        operPriority = new HashMap<>();
        operPriority.put('+', 1);
        operPriority.put('-', 1);
        operPriority.put('*', 2);
        operPriority.put('/', 2);
        operPriority.put('(', -99999);

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mInfix = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        mInfix = "(" + mInfix + ")";
    }

    public String infixToPostfix() {
        String postfix = "";
        Stack<Character> opers = new Stack<>();
        for (char c : mInfix.toCharArray()) {
            if(c >= 'A' && c <= 'Z') {
                postfix += c;
            } else if (c == '(') {
                opers.push(c);
            } else if (c == ')') {
                char oper = opers.pop();
                while (oper != '(') {
                    postfix += oper;
                    oper = opers.pop();
                }
            } else {
                while(true) {
                    if(operPriority.get(opers.peek()) < operPriority.get(c)) {
                        opers.push(c);
                        break;
                    }
                    postfix += opers.pop();
                }
            }
        }
        return postfix;
    }
}
