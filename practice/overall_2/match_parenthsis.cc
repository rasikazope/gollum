int maxLenMatchingParen(string strParenExpression) {

    stack <int> st;
    int index = 0;
    int max_val = 0;
    int len;

    for (int i = 0; i < strParenExpression.length(); i++) {
        if (strParenExpression[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                index = i + 1;
            } else {
                st.pop();
                len = st.empty() ? : i - index; i - st.top(); 
                if (len > max_val) 
                    max_val = len;
            }
        }
    }

    return max_val + 1;

}

