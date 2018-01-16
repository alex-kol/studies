const START_ARRAY = 0;
const ENGLISH_ALPHABET = 26;

var cryptKey = 0;
var enterString = "";
var sizeString = 0;

cryptKey = prompt("Input crypt key (number): ","");
if (!cryptKey){
    document.write("No entered key!");
    cryptKey = prompt("No entered key! Input key (number)!","");
}

enterString = prompt("Input the string: ","");
if (!enterString){
    document.write("No entered string!");
    enterString = prompt("No entered string! Input the string!","");
}
sizeString = enterString.length
for (i = START_ARRAY; i < sizeString; i++){
    if ((enterString[i] >= "a") && (enterString[i] <= "z")){
        enterString[i] = (enterString[i] + Number(cryptKey)) % ENGLISH_ALPHABET;
        if (enterString[i] > 'z'){
            enterString[i] = 'a' + (enterString[i] - 'z') - 1;
        }
    }
}
document.write("<br><br>You encryption string: " + enterString);

for (i = START_ARRAY; i < sizeString; i++){
    if ((enterString[i] >= 'a') && (enterString[i] <= 'z')){
        enterString[i] = enterString[i] - (cryptKey % ENGLISH_ALPHABET);
        if (enterString[i] < 'a'){
            enterString[i] = 'z' - ('a' - enterString[i]) + 1;
        }
    }
}
document.write("<br><br>You decryption string: " + enterString + "<br><br>");

