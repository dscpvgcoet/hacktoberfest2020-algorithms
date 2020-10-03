let values = [];

let i = 0;
let j = 0;

function setup() {
  createCanvas(900, 500);
  values = new Array(width);
  for (let i = 0; i < values.length; i++) {
    values[i] = random(height);
    setTimeout(1);
  }
}

function draw() {
  background(0);

  if (i < values.length) {
    for (let j = 0; j < values.length - 1; j++) {
      var min = j;
      for(let k=i+1;k<values.length;k++)
      if(values[k] < values[min])
      min = k;
      swap(values,j,min);
    }
  } else {
    console.log('finished');
    noLoop();
  }
  i++;

  for (let i = 0; i < values.length; i++) {
    stroke('red');
    line(i, height, i, height - values[i]);
  }
}

function swap(arr, a, b) {
  let temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}