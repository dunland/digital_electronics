/* 
JS script zum entfernen der paywall bei artikeln auf krautreporter.de 
Einfach F12 drücken und unten in die Konsole folgenden Code eingeben: */

document.querySelectorAll('p[data-krautmarkdown="data-krautmarkdown"]').forEach(element => {
    element.classList.remove('blurred');
});
