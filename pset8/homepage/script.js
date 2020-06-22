// countring the number of clicks
let counter = 0;
document.querySelector("html").onclick = function() {
    counter++;
    document.querySelector(".btn-success").innerHTML = "You have made " + counter + " clicks on this page";

};
// changing the style of the website
let color = "red";

document.querySelector("#borderChange").onclick = function() {
    document.querySelector("img").style.borderColor = color;
    document.querySelector("ul").style.backgroundColor = color;
    if (color === "red") {
        color = "green";
    } else if (color === "green") {
        color = "#B2BEC3"
    } else {
        color = "red"
    }
};