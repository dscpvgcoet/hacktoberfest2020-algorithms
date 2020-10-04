function integerPartition(number) {
  const partitionMatrix = Array(number + 1)
    .fill(null)
    .map(() => {
      return Array(number + 1).fill(null);
    });

  for (let numberIndex = 1; numberIndex <= number; numberIndex += 1) {
    partitionMatrix[0][numberIndex] = 0;
  }

  for (let summandIndex = 0; summandIndex <= number; summandIndex += 1) {
    partitionMatrix[summandIndex][0] = 1;
  }

  for (let summandIndex = 1; summandIndex <= number; summandIndex += 1) {
    for (let numberIndex = 1; numberIndex <= number; numberIndex += 1) {
      if (summandIndex > numberIndex) {
        partitionMatrix[summandIndex][numberIndex] =
          partitionMatrix[summandIndex - 1][numberIndex];
      } else {
        const combosWithoutSummand =
          partitionMatrix[summandIndex - 1][numberIndex];
        const combosWithSummand =
          partitionMatrix[summandIndex][numberIndex - summandIndex];

        partitionMatrix[summandIndex][numberIndex] =
          combosWithoutSummand + combosWithSummand;
      }
    }
  }

  return partitionMatrix[number][number];
}
