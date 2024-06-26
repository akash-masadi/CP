import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import javax.sound.sampled.*;

public class MusicPlayer implements ActionListener, ChangeListener {

    private JFrame frame;
    private JButton playButton, pauseButton, stopButton, nextButton, previousButton;
    private JFileChooser fileChooser;
    private JLabel songLabel;
    private JSlider volumeSlider;
    private Clip clip;
    private File currentFile;

    public MusicPlayer() {
        initializeGUI();
    }

    private void initializeGUI() {
        frame = new JFrame("Music Player");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new FlowLayout());

        // Buttons
        playButton = new JButton("Play");
        playButton.addActionListener(this);
        pauseButton = new JButton("Pause");
        pauseButton.addActionListener(this);
        pauseButton.setEnabled(false);
        stopButton = new JButton("Stop");
        stopButton.addActionListener(this);
        stopButton.setEnabled(false);
        nextButton = new JButton("Next");
        nextButton.addActionListener(this);
        nextButton.setEnabled(false);
        previousButton = new JButton("Previous");
        previousButton.addActionListener(this);
        previousButton.setEnabled(false);

        // File Chooser
        fileChooser = new JFileChooser();
        fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);

        // Song Label
        songLabel = new JLabel("No song selected");

        // Volume Slider
        volumeSlider = new JSlider(JSlider.HORIZONTAL, 0, 100, 100);
        volumeSlider.addChangeListener(this);

        // Add components to frame
        frame.add(playButton);
        frame.add(pauseButton);
        frame.add(stopButton);
        frame.add(nextButton);
        frame.add(previousButton);
        frame.add(songLabel);
        frame.add(volumeSlider);

        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == playButton) {
            if (currentFile != null) {
                try {
                    AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(currentFile);
                    clip = AudioSystem.getClip();
                    clip.open(audioInputStream);
                    clip.start();
                    playButton.setEnabled(false);
                    pauseButton.setEnabled(true);
                    stopButton.setEnabled(true);
                } catch (UnsupportedAudioFileException | IOException | LineUnavailableException ex) {
                    JOptionPane.showMessageDialog(frame, "Error playing song: " + ex.getMessage());
                }
            } else {
                int result = fileChooser.showOpenDialog(frame);
                if (result == JFileChooser.APPROVE_OPTION) {
                    currentFile = fileChooser.getSelectedFile();
                    songLabel.setText(currentFile.getName());
                    playButton.setEnabled(true);
                    nextButton.setEnabled(true);
                    previousButton.setEnabled(true);
                }
            }
        } else if (e.getSource() == pauseButton) {
            if (clip.isRunning()) {
                clip.stop();
                playButton.setEnabled(true);
                pauseButton.setEnabled(false);
            }
        } else if (e.getSource() == stopButton) {
            if (clip.isRunning()) {
                clip.stop();
            }
            playButton.setEnabled(true);
            pauseButton.setEnabled(false);
            stopButton.setEnabled(false);
        } else if (e.getSource() == nextButton || e.getSource() == previousButton) {
            // Implement logic to navigate to next/previous song
            // This would require storing a list of songs and 
            // updating the currentFile accordingly
        }
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        if (e.getSource() == volumeSlider) {
            float volume = (float) volumeSlider.getValue() / 100f;
            if (clip != null) {
                FloatControl gainControl = (FloatControl) clip.getControl(FloatControl.Type.MASTER_GAIN);
                gainControl.setValue(20f * (float) Math.log10(volume));
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new MusicPlayer());
    }
}