document.addEventListener("DOMContentLoaded", function() {
    let p = document.querySelector("p");
    let mydiv=document.querySelector("div");
    mydiv.addEventListener("mouseover", function() {
        p.textContent = "Mouse over button!";
    });

    mydiv.addEventListener("mouseout", function() {
        p.textContent = "Mouse out of button!";
    });

    mydiv.addEventListener("click", function() {
        p.textContent = "Button clicked!";
    });
});