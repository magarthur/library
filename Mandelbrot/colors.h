#ifndef COLORS_H
#define COLORS_H

/* Une structure pour représenter une couleur, quel que soit
 * le modèle choisi (tant qu'il utilise 3 composantes).
 */
struct color {
	double c1, c2, c3 ;	/* Composantes de la couleur rgb, hsv, hsl, ... */
} ;


/* Convertit une couleur exprimée en HSV en une couleur
 * exprimée en RGB.
 *
 * Voir https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
 */
void hsv2rgb(struct color *rgb, struct color *hsv)
{
	double hp ;		/* h' : quadrant sur le cercle de la teinte */
	double c, x, m ;
	double r, g, b ;

	if ( hsv->c3 > 1.0 ) hsv->c3 = 1.0 ;
	hp = hsv->c1/60 ;
	c = hsv->c2 * hsv->c3 ;		/* Chrominance (saturation \times valeur) */
	x = c*(1 - fabs(fmod(hp, 2) - 1));
	r = 0;
	g = 0;
	b = 0;

	if ( 0<=hp && hp<1 ) {	/* de rouge à jaune */
		/*  c, x, 0 */
		r = c;
		g = x;
	}
	else if ( 1<=hp && hp<2 ) {	/* de jaune à vert */
		/*  x, c, 0 */
		r = x;
		g = c;
	}
	else if ( 2<=hp && hp<3 ) {	/* de vert à cyan */
		/*  0, c, x */
		g = c;
		b = x;
	}
	else if ( 3<=hp && hp<4 ) {	/* de cyan à bleu */
		/*  0, x, c */
		g = x;
		b = c;
	}
	else if ( 4<=hp && hp<5 ) {	/* de bleu à magenta */
		/*  x, 0, c */
		r = x;
		b = c;
	}
	else if ( 5<=hp && hp<6 ) {	/* de magenta à rouge */
		/*  c, 0, x */
		r = c;
		b = x;
	}

	m = hsv->c3 - c;
	r += m;
	g += m;
	b += m;

	rgb->c1 = r * 255;
	rgb->c2 = g * 255;
	rgb->c3 = b * 255;
}

#endif
