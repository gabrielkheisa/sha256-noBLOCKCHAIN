# sha256-noBLOCKCHAIN

Just want to compare hashes, not real blockchain and just a concept.

Original block<br>
"A to B 200 coins, B to C 100 coins, C to D 50 coins, D to A 25 coins"<br>
"D to E 200 coins, E to F 100 coins, F to G 50 coins, G to D 25 coins"<br>
"H to I 200 coins, I to J 100 coins, J to K 50 coins, K to L 25 coins"<br>
"X to Z 200 coins, AA to BB 100 coins, CC to DD 50 coins, DD to AA 25 coins"<br>
"AAA to BBB 200 coins, BBB to CCC 100 coins, CCC to DDD 50 coins, DDD to AAA 25 coins"<br>
"AA to BBB 200 coins, BB to CC 100 coins, CC to DD 50 coins, DD to AA 25 coins"<br><br>

Fake block<br>
"A to B 200 coins, B to C 100 coins, C to D 50 coins, D to A 25 coins"<br>
"D to E 200 coins, E to F 100 coins, F to G 50 coins, G to D 25 coins"<br>
"H to I 200 coins, I to J 133 coins, J to K 50 coins, K to L 25 coins"<br>
"X to Z 200 coins, AA to BB 100 coins, CC to DD 50 coins, DD to AA 25 coins"<br>
"AAA to BBB 200 coins, BBB to CCC 100 coins, CCC to DDD 50 coins, DDD to AAA 25 coins"<br>
"AA to BBB 200 coins, BB to CC 100 coins, CC to DD 50 coins, DD to AA 25 coins"<br><br>

Output:<br>
Block-0 valid<br>
Block-1 valid<br>
Block-2 valid<br>
Block-3 valid<br>
Block-4 valid<br><br>

Block-0 valid<br>
Block-1 valid<br>
Block-2 invalid<br>
Rejected<br><br>

<img src="https://www.researchgate.net/profile/Yahya_Shahsavari/publication/331639364/figure/fig2/AS:755068626276352@1557033797702/Blockchain-data-structure.ppm">

