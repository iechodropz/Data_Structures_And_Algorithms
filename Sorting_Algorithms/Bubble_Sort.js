const bubbleSort = (array) => {
	for (let i = 0; i < array.length - 1; i++) {
		let flag = 0;
		for (let j = 0; j < array.length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				let temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				flag = 1;
			}
		}

		if (flag === 0) {
			break;
		}
	}
};


// // ***********************************************************
// console.log("Example for sorting an array using Bubble Sort.");

// testBubbleSort = [4, 3, 7, 9, 8, 2, 1, 5, 0, 6];

// testBubbleSort.forEach((element) => {
// 	process.stdout.write(element.toString() + " ");
// });

// console.log("\n");

// bubbleSort(testBubbleSort);

// testBubbleSort.forEach((element) => {
// 	process.stdout.write(element.toString() + " ");
// });

// console.log("\n");
// // ***********************************************************************************