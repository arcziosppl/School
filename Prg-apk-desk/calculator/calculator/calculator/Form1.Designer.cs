namespace calculator
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.n9 = new System.Windows.Forms.Button();
            this.n4 = new System.Windows.Forms.Button();
            this.n1 = new System.Windows.Forms.Button();
            this.bc = new System.Windows.Forms.Button();
            this.n0 = new System.Windows.Forms.Button();
            this.ndot = new System.Windows.Forms.Button();
            this.n2 = new System.Windows.Forms.Button();
            this.n3 = new System.Windows.Forms.Button();
            this.n5 = new System.Windows.Forms.Button();
            this.n6 = new System.Windows.Forms.Button();
            this.n8 = new System.Windows.Forms.Button();
            this.n7 = new System.Windows.Forms.Button();
            this.bdiv = new System.Windows.Forms.Button();
            this.bmul = new System.Windows.Forms.Button();
            this.bad = new System.Windows.Forms.Button();
            this.bsub = new System.Windows.Forms.Button();
            this.nequal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(43, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(174, 20);
            this.textBox1.TabIndex = 0;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // n9
            // 
            this.n9.Location = new System.Drawing.Point(43, 38);
            this.n9.Name = "n9";
            this.n9.Size = new System.Drawing.Size(39, 23);
            this.n9.TabIndex = 1;
            this.n9.Text = "9";
            this.n9.UseVisualStyleBackColor = true;
            this.n9.Click += new System.EventHandler(this.n9_Click);
            // 
            // n4
            // 
            this.n4.Location = new System.Drawing.Point(43, 67);
            this.n4.Name = "n4";
            this.n4.Size = new System.Drawing.Size(39, 23);
            this.n4.TabIndex = 2;
            this.n4.Text = "4";
            this.n4.UseVisualStyleBackColor = true;
            this.n4.Click += new System.EventHandler(this.n4_Click);
            // 
            // n1
            // 
            this.n1.Location = new System.Drawing.Point(43, 96);
            this.n1.Name = "n1";
            this.n1.Size = new System.Drawing.Size(39, 23);
            this.n1.TabIndex = 3;
            this.n1.Text = "1";
            this.n1.UseVisualStyleBackColor = true;
            this.n1.Click += new System.EventHandler(this.n1_Click);
            // 
            // bc
            // 
            this.bc.Location = new System.Drawing.Point(43, 125);
            this.bc.Name = "bc";
            this.bc.Size = new System.Drawing.Size(39, 23);
            this.bc.TabIndex = 4;
            this.bc.Text = "C";
            this.bc.UseVisualStyleBackColor = true;
            this.bc.Click += new System.EventHandler(this.bc_Click);
            // 
            // n0
            // 
            this.n0.Location = new System.Drawing.Point(88, 125);
            this.n0.Name = "n0";
            this.n0.Size = new System.Drawing.Size(39, 23);
            this.n0.TabIndex = 5;
            this.n0.Text = "0";
            this.n0.UseVisualStyleBackColor = true;
            this.n0.Click += new System.EventHandler(this.n0_Click);
            // 
            // ndot
            // 
            this.ndot.Location = new System.Drawing.Point(133, 125);
            this.ndot.Name = "ndot";
            this.ndot.Size = new System.Drawing.Size(39, 23);
            this.ndot.TabIndex = 6;
            this.ndot.Text = ".";
            this.ndot.UseVisualStyleBackColor = true;
            this.ndot.Click += new System.EventHandler(this.ndot_Click);
            // 
            // n2
            // 
            this.n2.Location = new System.Drawing.Point(88, 96);
            this.n2.Name = "n2";
            this.n2.Size = new System.Drawing.Size(39, 23);
            this.n2.TabIndex = 7;
            this.n2.Text = "2";
            this.n2.UseVisualStyleBackColor = true;
            this.n2.Click += new System.EventHandler(this.n2_Click);
            // 
            // n3
            // 
            this.n3.Location = new System.Drawing.Point(133, 96);
            this.n3.Name = "n3";
            this.n3.Size = new System.Drawing.Size(39, 23);
            this.n3.TabIndex = 8;
            this.n3.Text = "3";
            this.n3.UseVisualStyleBackColor = true;
            this.n3.Click += new System.EventHandler(this.n3_Click);
            // 
            // n5
            // 
            this.n5.Location = new System.Drawing.Point(88, 67);
            this.n5.Name = "n5";
            this.n5.Size = new System.Drawing.Size(39, 23);
            this.n5.TabIndex = 9;
            this.n5.Text = "5";
            this.n5.UseVisualStyleBackColor = true;
            this.n5.Click += new System.EventHandler(this.n5_Click);
            // 
            // n6
            // 
            this.n6.Location = new System.Drawing.Point(133, 67);
            this.n6.Name = "n6";
            this.n6.Size = new System.Drawing.Size(39, 23);
            this.n6.TabIndex = 10;
            this.n6.Text = "6";
            this.n6.UseVisualStyleBackColor = true;
            this.n6.Click += new System.EventHandler(this.n6_Click);
            // 
            // n8
            // 
            this.n8.Location = new System.Drawing.Point(88, 38);
            this.n8.Name = "n8";
            this.n8.Size = new System.Drawing.Size(39, 23);
            this.n8.TabIndex = 11;
            this.n8.Text = "8";
            this.n8.UseVisualStyleBackColor = true;
            this.n8.Click += new System.EventHandler(this.n8_Click);
            // 
            // n7
            // 
            this.n7.Location = new System.Drawing.Point(133, 38);
            this.n7.Name = "n7";
            this.n7.Size = new System.Drawing.Size(39, 23);
            this.n7.TabIndex = 12;
            this.n7.Text = "7";
            this.n7.UseVisualStyleBackColor = true;
            this.n7.Click += new System.EventHandler(this.n7_Click);
            // 
            // bdiv
            // 
            this.bdiv.Location = new System.Drawing.Point(178, 38);
            this.bdiv.Name = "bdiv";
            this.bdiv.Size = new System.Drawing.Size(39, 23);
            this.bdiv.TabIndex = 13;
            this.bdiv.Text = "/";
            this.bdiv.UseVisualStyleBackColor = true;
            this.bdiv.Click += new System.EventHandler(this.bdiv_Click);
            // 
            // bmul
            // 
            this.bmul.Location = new System.Drawing.Point(178, 67);
            this.bmul.Name = "bmul";
            this.bmul.Size = new System.Drawing.Size(39, 23);
            this.bmul.TabIndex = 14;
            this.bmul.Text = "*";
            this.bmul.UseVisualStyleBackColor = true;
            this.bmul.Click += new System.EventHandler(this.bmul_Click);
            // 
            // bad
            // 
            this.bad.Location = new System.Drawing.Point(178, 96);
            this.bad.Name = "bad";
            this.bad.Size = new System.Drawing.Size(39, 23);
            this.bad.TabIndex = 15;
            this.bad.Text = "+";
            this.bad.UseVisualStyleBackColor = true;
            this.bad.Click += new System.EventHandler(this.bad_Click);
            // 
            // bsub
            // 
            this.bsub.Location = new System.Drawing.Point(178, 125);
            this.bsub.Name = "bsub";
            this.bsub.Size = new System.Drawing.Size(39, 23);
            this.bsub.TabIndex = 16;
            this.bsub.Text = "-";
            this.bsub.UseVisualStyleBackColor = true;
            this.bsub.Click += new System.EventHandler(this.bsub_Click);
            // 
            // nequal
            // 
            this.nequal.Location = new System.Drawing.Point(43, 154);
            this.nequal.Name = "nequal";
            this.nequal.Size = new System.Drawing.Size(174, 23);
            this.nequal.TabIndex = 17;
            this.nequal.Text = "=";
            this.nequal.UseVisualStyleBackColor = true;
            this.nequal.Click += new System.EventHandler(this.nequal_Click);
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(267, 239);
            this.Controls.Add(this.nequal);
            this.Controls.Add(this.bsub);
            this.Controls.Add(this.bad);
            this.Controls.Add(this.bmul);
            this.Controls.Add(this.bdiv);
            this.Controls.Add(this.n7);
            this.Controls.Add(this.n8);
            this.Controls.Add(this.n6);
            this.Controls.Add(this.n5);
            this.Controls.Add(this.n3);
            this.Controls.Add(this.n2);
            this.Controls.Add(this.ndot);
            this.Controls.Add(this.n0);
            this.Controls.Add(this.bc);
            this.Controls.Add(this.n1);
            this.Controls.Add(this.n4);
            this.Controls.Add(this.n9);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }


        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button n9;
        private System.Windows.Forms.Button n4;
        private System.Windows.Forms.Button n1;
        private System.Windows.Forms.Button bc;
        private System.Windows.Forms.Button n0;
        private System.Windows.Forms.Button ndot;
        private System.Windows.Forms.Button n2;
        private System.Windows.Forms.Button n3;
        private System.Windows.Forms.Button n5;
        private System.Windows.Forms.Button n6;
        private System.Windows.Forms.Button n8;
        private System.Windows.Forms.Button n7;
        private System.Windows.Forms.Button bdiv;
        private System.Windows.Forms.Button bmul;
        private System.Windows.Forms.Button bad;
        private System.Windows.Forms.Button bsub;
        private System.Windows.Forms.Button nequal;
    }
}

