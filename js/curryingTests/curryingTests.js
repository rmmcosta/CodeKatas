//const filter = when => what => 
const fruits = ['apples', 'grapes', 'strawberries', 'bananas', 'pears', 'peachs', 'pineaple'];

let fruitsStartedWithP = fruits.filter(each => each[0] === 'p');
console.log(fruitsStartedWithP);
const fruitsFilter = theFilter => theFruits => theFruits.filter(theFilter);
fruitsStartedWithP = fruitsFilter(each => each[each.length - 2] === 'e')(fruits);
console.log(fruitsStartedWithP);
fruitsStartedWithP = fruitsFilter(each => each[0] === 'a')(fruits);
console.log(fruitsStartedWithP);

let memoryCanEatPeel = [];

function canEatPeel(fruit) {
    const hardPeelFruits = ['bananas', 'pineaple'];
    let hasHardPeel = false;
    if (memoryCanEatPeel[fruit] !== undefined) {
        console.log('memory used');
        return memoryCanEatPeel[fruit];
    }
    for (let i = 0; i < hardPeelFruits.length; i++) {
        if (fruit === hardPeelFruits[i]) {
            hasHardPeel = true;
            break;
        }
    }
    memoryCanEatPeel[fruit] = hasHardPeel;
    console.log('memory not used');
    return !hasHardPeel;
}

fruits.forEach(each => console.log(`can I eat ${each} peel`, canEatPeel(each)));
fruits.forEach(each => console.log(`can I eat ${each} peel`, canEatPeel(each)));