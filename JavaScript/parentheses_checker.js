function parentheses(str) {
  let stack = [];
  let map = {
    "(": ")",
    "[": "]",
    "{": "}",
  };

  for (let i = 0; i < str.length; i++) {
    if (str[i] === "(" || str[i] === "{" || str[i] === "[") {
      stack.push(str[i]);
    } else {
      let lastEle = stack.pop();

      if (str[i] !== map[lastEle]) {
        return false;
      }
    }
  }

  if (stack.length !== 0) {
    return false;
  }

  return true;
}

console.log(balancedParentheses("{[]()}"));
console.log(balancedParentheses("{[(])}"));
console.log(balancedParentheses("{[}"));
