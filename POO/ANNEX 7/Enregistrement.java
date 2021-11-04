package packageannexe7;

public class Enregistrement {
    private String nomUser;
    private String password;
    private String email;

    public Enregistrement(String nomUser, String password, String email){
        this.nomUser = nomUser;
        this.password = password;
        this.email = email;
    }

    //get
    public String getEmail() {return email;}

    public String getNomUser() {return nomUser;}

    public String getPassword() {return password;}

    //set
    public void setEmail(String email) {this.email = email;}

    public void setNomUser(String nomUser) {this.nomUser = nomUser;}

    public void setPassword(String password) {this.password = password;}
}
