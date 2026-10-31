using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using System.IO;
using System.Xml;
using System.Globalization;

namespace lab08
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void CalculateResults()
        {
            double[] xValues = { 1.3, 1.5, 1.8, 2.0 };
            double[] aValues = { 0.7, 0.85, 0.9 };
            double b = 5.75;

            double sum = 0;

            dataGridViewResults.Columns.Clear();
            dataGridViewResults.Rows.Clear();

            dataGridViewResults.Columns.Add("ColumnX", "x");
            dataGridViewResults.Columns.Add("ColumnA", "a");
            dataGridViewResults.Columns.Add("ColumnZ", "z");
            dataGridViewResults.Columns.Add("ColumnY", "y");

            foreach (double x in xValues)
            {
                double z = Math.Exp(-1.0 / x) + x - b - Math.Cos(x);

                foreach (double a in aValues)
                {
                    double y = Math.Pow(z, 3)
                        - (z + a - b) / (Math.Pow(a, 0.4) + Math.Pow(z, 2));

                    dataGridViewResults.Rows.Add(
                        x.ToString("F2"),
                        a.ToString("F2"),
                        z.ToString("F4"),
                        y.ToString("F4")
                    );

                    sum += y;
                }
            }

            lblSum.Text = "Сума всіх значень: " + sum.ToString("F4");
        }
        
        private void SaveResultsToXml(string filePath)
        {
            if (dataGridViewResults.Rows.Count == 0 ||
                dataGridViewResults.Columns.Count < 4)
            {
                MessageBox.Show(
                    "Спочатку обчисліть значення.",
                    "Збереження",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);

                return;
            }

            XmlWriterSettings settings = new XmlWriterSettings
            {
                Indent = true
            };

            using (XmlWriter writer = XmlWriter.Create(filePath, settings))
            {
                writer.WriteStartDocument();
                writer.WriteStartElement("Results");

                foreach (DataGridViewRow row in dataGridViewResults.Rows)
                {
                    if (row.IsNewRow)
                        continue;

                    writer.WriteStartElement("Result");

                    writer.WriteElementString(
                        "X",
                        Convert.ToString(row.Cells[0].Value));

                    writer.WriteElementString(
                        "A",
                        Convert.ToString(row.Cells[1].Value));

                    writer.WriteElementString(
                        "Z",
                        Convert.ToString(row.Cells[2].Value));

                    writer.WriteElementString(
                        "Y",
                        Convert.ToString(row.Cells[3].Value));

                    writer.WriteEndElement();
                }

                writer.WriteEndElement();
                writer.WriteEndDocument();
            }

            MessageBox.Show(
                "Результати успішно збережено.",
                "Збереження",
                MessageBoxButtons.OK,
                MessageBoxIcon.Information);
        }
        
        private void LoadResultsFromXml(string filePath)
        {
            try
            {
                DataSet dataSet = new DataSet();
                dataSet.ReadXml(filePath);

                if (!dataSet.Tables.Contains("Result"))
                {
                    MessageBox.Show(
                        "Файл не містить таблиці результатів.",
                        "Відкриття XML",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Warning);

                    return;
                }

                DataTable table = dataSet.Tables["Result"];

                string[] requiredColumns = { "X", "A", "Z", "Y" };

                foreach (string column in requiredColumns)
                {
                    if (!table.Columns.Contains(column))
                    {
                        MessageBox.Show(
                            "XML-файл має неправильну структуру.",
                            "Відкриття XML",
                            MessageBoxButtons.OK,
                            MessageBoxIcon.Warning);

                        return;
                    }
                }

                dataGridViewResults.Columns.Clear();
                dataGridViewResults.Rows.Clear();

                dataGridViewResults.Columns.Add("ColumnX", "x");
                dataGridViewResults.Columns.Add("ColumnA", "a");
                dataGridViewResults.Columns.Add("ColumnZ", "z");
                dataGridViewResults.Columns.Add("ColumnY", "y");

                foreach (DataRow row in table.Rows)
                {
                    dataGridViewResults.Rows.Add(
                        Convert.ToString(row["X"]),
                        Convert.ToString(row["A"]),
                        Convert.ToString(row["Z"]),
                        Convert.ToString(row["Y"]));
                }

                MessageBox.Show(
                    "Результати успішно завантажено.",
                    "Відкриття XML",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(
                    "Не вдалося відкрити файл:\n" + ex.Message,
                    "Помилка",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            CalculateResults();
        }

        private void calculateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CalculateResults();
        }

        private void sumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            double sum = 0;

            foreach (DataGridViewRow row in dataGridViewResults.Rows)
            {
                if (row.IsNewRow)
                    continue;

                if (double.TryParse(
                    Convert.ToString(row.Cells[3].Value),
                    out double y))
                {
                    sum += y;
                }
            }

            lblSum.Text = "Сума всіх значень: " + sum.ToString("F4");
        }

        private void plotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (dataGridViewResults.Rows.Count == 0 ||
        dataGridViewResults.Columns.Count < 4)
            {
                MessageBox.Show(
                    "Спочатку обчисліть значення.",
                    "Побудова графіка",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);

                return;
            }

            chartResults.Series.Clear();
            chartResults.ChartAreas.Clear();

            ChartArea chartArea = new ChartArea("MainArea");
            chartResults.ChartAreas.Add(chartArea);

            chartResults.Titles.Clear();
            chartResults.Titles.Add("Графік функції y(x) для різних значень a");

            chartArea.AxisX.Title = "x";
            chartArea.AxisY.Title = "y";

            chartArea.AxisX.MajorGrid.Enabled = true;
            chartArea.AxisY.MajorGrid.Enabled = true;

            double[] aValues = { 0.7, 0.85, 0.9 };

            foreach (double aValue in aValues)
            {
                Series series = new Series("a = " + aValue.ToString("0.##"));

                series.ChartType = SeriesChartType.Line;
                series.BorderWidth = 2;
                series.MarkerStyle = MarkerStyle.Circle;
                series.MarkerSize = 7;

                foreach (DataGridViewRow row in dataGridViewResults.Rows)
                {
                    if (row.IsNewRow)
                        continue;

                    double x = Convert.ToDouble(row.Cells[0].Value);
                    double a = Convert.ToDouble(row.Cells[1].Value);
                    double y = Convert.ToDouble(row.Cells[3].Value);

                    if (Math.Abs(a - aValue) < 0.001)
                    {
                        series.Points.AddXY(x, y);
                    }
                }

                chartResults.Series.Add(series);
            }

            if (chartResults.Legends.Count == 0)
            {
                chartResults.Legends.Add(new Legend("MainLegend"));
            }

            chartResults.Legends[0].Enabled = true;
        }

        private void plotToolStripButton_Click(object sender, EventArgs e)
        {
            plotToolStripMenuItem_Click(sender, e);
        }

        private void plotContextMenuItem_Click(object sender, EventArgs e)
        {
            plotToolStripMenuItem_Click(sender, e);
        }

        private void saveXmlToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog dialog = new SaveFileDialog())
            {
                dialog.Filter = "XML-файли (*.xml)|*.xml";
                dialog.Title = "Збереження результатів";
                dialog.FileName = "results.xml";

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    SaveResultsToXml(dialog.FileName);
                }
            }
        }

        private void openXmlToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dialog = new OpenFileDialog())
            {
                dialog.Filter = "XML-файли (*.xml)|*.xml";
                dialog.Title = "Відкриття результатів";

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    LoadResultsFromXml(dialog.FileName);
                }
            }
        }

        private void saveAsXmlToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog dialog = new SaveFileDialog())
            {
                dialog.Filter = "XML-файли (*.xml)|*.xml";
                dialog.Title = "Збереження результатів як XML";
                dialog.FileName = "results_copy.xml";
                dialog.OverwritePrompt = true;

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    SaveResultsToXml(dialog.FileName);
                }
            }
        }

        private void createTableToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dataGridViewResults.Columns.Clear();
            dataGridViewResults.Rows.Clear();

            dataGridViewResults.Columns.Add("ColumnX", "x");
            dataGridViewResults.Columns.Add("ColumnA", "a");
            dataGridViewResults.Columns.Add("ColumnZ", "z");
            dataGridViewResults.Columns.Add("ColumnY", "y");

            lblSum.Text = "Сума всіх значень: 0";

            chartResults.Series.Clear();
            chartResults.Titles.Clear();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(
        "Програма для обчислення значень функції та побудови графіка.\n\n" +
        "Можливості програми:\n" +
        "• Обчислення значень x, a, z та y;\n" +
        "• Обчислення суми значень y;\n" +
        "• Побудова графіка функції;\n" +
        "• Збереження та відкриття результатів у форматі XML.\n\n" +
        "Варіант 10",
        "Про програму",
        MessageBoxButtons.OK,
        MessageBoxIcon.Information);
        }

        private void sumToolStripButton_Click(object sender, EventArgs e)
        {
            sumToolStripMenuItem_Click(sender, e);
        }

        private void openToolStripButton_Click(object sender, EventArgs e)
        {
            openXmlToolStripMenuItem_Click(sender, e);
        }

        private void saveToolStripButton_Click(object sender, EventArgs e)
        {
            saveXmlToolStripMenuItem_Click(sender, e);
        }

        private void calculateContextMenuItem_Click(object sender, EventArgs e)
        {
            calculateToolStripMenuItem_Click(sender, e);
        }

        private void sumContextMenuItem_Click(object sender, EventArgs e)
        {
            sumToolStripMenuItem_Click(sender, e);
        }
    }
}
