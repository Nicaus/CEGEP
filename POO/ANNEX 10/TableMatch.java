package projetannexe10;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TableMatch {
    private JPanel panel1;
    private JSpinner spinner;
    private JCheckBox ouiCheckBox;
    private JButton bouton;
    private JLabel labelNumeroTable;
    private JLabel labelNbTablesOccupees;

    public TableMatch()
    {
        spinner.setModel(new SpinnerNumberModel(2,2,4,1));
        Ecouteur ec = new Ecouteur ();
        bouton.addActionListener ( ec );

    }


    private class Ecouteur implements ActionListener {
        Restaurant r = new Restaurant ();

        public void actionPerformed ( ActionEvent ae) {
            int nb =(Integer) spinner.getValue();
            boolean banquette = ouiCheckBox.isSelected();

            // codez ici !

            //écrire le numéro dans labelNumeroTable
            Table t = r.assignerTableDispo(nb, banquette);

            if (t!= null){
                labelNumeroTable.setText(String.valueOf(t.getNumero()));
            }

            // afficher le nbre de tables occupées

            labelNbTablesOccupees.setText("Nb table " + r.nbTableOcupees());

        }
    }
    public static void main(String[] args) {
        JFrame frame = new JFrame("TableMatch");
        frame.setContentPane(new TableMatch().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize( 700,500);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);



    }


}
