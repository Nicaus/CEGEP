package packageannexe6b;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FrameString {
    private JPanel monPanel;
    private JTextArea champString;
    private JButton boutonResultats;
    private JTextField champMot;
    private JPanel panelNo6;
    private JLabel reponse1;
    private JLabel reponse3;
    private JLabel reponse2;
    private JLabel reponse4;
    private JLabel reponse5;
    private JLabel reponse6;


    public static void main(String[] args) {
        JFrame frame = new JFrame("FrameString");
        frame.setContentPane(new FrameString().monPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setSize(1100, 600);
        //frame.pack();
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
    }
    public FrameString()
    {
        Ecouteur ec = new Ecouteur ();
        boutonResultats.addActionListener(ec);
    }

    private class Ecouteur implements ActionListener
    {

        @Override
        public void actionPerformed(ActionEvent e) {
            //contenu du champ texte
            String texte = champString.getText();

            // codez ici question 1 ( caractère à l'indice 8 )
            reponse1.setText(""+texte.charAt(7));

            // codez ici question 2 ( indice du premier e )
            reponse2.setText(""+texte.indexOf("e"));

            // codez ici question 3 ( indice du dernier e )
            reponse3.setText(""+texte.lastIndexOf("e"));

            // codez ici question 4 ( nombre de caractères de la phrase )
            reponse4.setText(""+texte.length());

            // codez ici question 5 ( commence par une majuscule ) ( chercher dans classe Character )

            boolean test = Character.isUpperCase(texte.charAt(0));
            reponse5.setText(""+test);

            // codez ici question 6 ( nombre d'occurences d'un mot )
            String mot = champMot.getText();
            String[] a = texte.split("\\W");
            int nb = 0;
            for (int i = 0; i < a.length; i++){
                if (mot.equals(a[i])) {
                    nb += 1;
                }
            }
             reponse6.setText(""+nb);

//            String mot = champMot.getText();
//            trouverNbOccurances(texte, mot);


        }
        public int trouverNbOccurances (String texte, String mot){
            int compteur = 0;
            int index = 0;
            index = texte.indexOf(mot);

            while (index != -1){
                compteur++;
                index = texte.indexOf(mot, index+1);
            }

            return compteur;
        }
        
        public int trouverNbOccurencesMatcherPattern (String texte, String mot){
            int nb = 0;
            Pattern p = Pattern.compile(mot);
            Matcher m = p.matcher(texte);

            while(m.find()) {nb++;}
            return nb;
        }

        }
    }

