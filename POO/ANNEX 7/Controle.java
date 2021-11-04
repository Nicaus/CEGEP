package packageannexe7;

public class Controle {

//    verification d'input
    public boolean vNom (Enregistrement a){
        String nom = a.getNomUser();

        return nom.matches("R[1-3][A-Z][a-z]{4}[A-Z][a-z]");
    }

    public boolean vEmail (Enregistrement a){
        String email = a.getEmail();

//        Pattern p = Pattern.compile("@");
//        Matcher m = p.matcher(a.getEmail());
//        return m.find();

        return email.matches("^(.+)@(.+)$");
//        return email.matches("\\S+@\\S+");

    }

    public boolean vPassword (Enregistrement a){
        String password = a.getPassword();

        return password.matches("(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z]).{8,}");
//        if (password.length() >= 8)
//            if (password.matches("\\S*[A-Z]\\S*"))
//                if (password.matches("\\S*\\d\\S*"))
//                    return true;
//        return false;
    }
}
