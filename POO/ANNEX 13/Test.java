package annexe13;

import java.text.DateFormat;
import java.text.FieldPosition;
import java.text.ParsePosition;
import java.util.Date;

public class Test {
    public static void main(String[] args) {
        Maison m1 = new Maison(5,400,"12", "rue Roy", 180000);
        Maison m2 = new Maison(6, 230, "15", "rue Roy", 195000);
        Chalet c = new Chalet(4, 600, "33", "Desilets", 120000, true, true);
        MaisonMobile mm = new MaisonMobile(5, 80500, true, true, 1994);

        DateFormat df = new DateFormat() {
            @Override
            public StringBuffer format(Date date, StringBuffer toAppendTo, FieldPosition fieldPosition) {
                return null;
            }

            @Override
            public Date parse(String source, ParsePosition pos) {
                return null;
            }
        };

        System.out.println(df.format(m1.valeur()));

        c.ajouterPieces(2);

        System.out.println(df.format(c.valeur()));

        m1.setSuperficie(500);

        System.out.println(df.format(m1.meilleureAffaire(m2)));
    }
}
