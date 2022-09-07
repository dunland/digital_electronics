// licensed with CC BY-NC-SA 4.0
// https://creativecommons.org/licenses/by-nc-sa/4.0/ edited after @naoto_hieda

solid(0.9, 0.6, 0.9)

    .layer(osc(31.4, 0)
               .thresh(0.7)
               .luma()
               .modulate(osc(4, 1).rotate(1), () => a.fft[2])
               .color(0, 0, 0))

    .layer(osc(31.4, 0)
               .thresh(0.7)
               .luma()
               .modulate(osc(4, 1).rotate(1), () => a.fft[0])
               .color(0.05, 0.5, 0.7))

    .out()
