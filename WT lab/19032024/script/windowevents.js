document.addEventListener("DOMContentLoaded", function() {
    let p = document.querySelector("p");

    window.addEventListener("resize", function() {
        p.textContent = "Resizing";
    });
    window.addEventListener("load", function() {
        p.textContent = "Loading Successful! Let's go!";
    });
});
