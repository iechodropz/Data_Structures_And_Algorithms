const selectionSort = (array) => {
	for (let i = 0; i < array.length - 1; i++) {
		let minElementIndex = i;

		for (let j = i + 1; j < array.length; j++) {
			if (array[j] < array[minElementIndex]) {
				minElementIndex = j;
			}
		}

		let temp = array[i];
		array[i] = array[minElementIndex];
		array[minElementIndex] = temp;
	}
};

// // ****************************************************************************
// console.log("Example for sorting an array using Selection Sort.");

// testSelectionSort = [4, 3, 7, 9, 8, 2, 1, 5, 0, 6];

// testSelectionSort.forEach((element) => {
// 	process.stdout.write(element.toString() + " ");
// });

// console.log("\n");

// selectionSort(testSelectionSort);

// testSelectionSort.forEach((element) => {
// 	process.stdout.write(element.toString() + " ");
// });

// console.log("\n");
// // ***********************************************************************************