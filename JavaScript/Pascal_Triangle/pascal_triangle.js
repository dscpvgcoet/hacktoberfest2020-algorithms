function pascalTriangle(lineNum) {
  const currentLine = [1];

  const currentLineSize = lineNum + 1;

  for (let numIndex = 1; numIndex < currentLineSize; numIndex += 1) {
    currentLine[numIndex] =
      (currentLine[numIndex - 1] * (lineNum - numIndex + 1)) / numIndex;
  }

  return currentLine;
}
