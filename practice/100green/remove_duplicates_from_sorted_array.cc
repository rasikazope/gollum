
Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i < A.size() - 1 && A[i] == A[i+1])  continue;
        else {
            A[count] = A[i];
            count++;
        }
    }
    return count;
    
}

